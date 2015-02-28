# $NetBSD: hacks.mk,v 1.2 2015/02/28 14:30:56 tnn Exp $

.if !defined(OPENJDK8_HACKS_MK)
OPENJDK8_HACKS_MK=	# empty

### Ensure we do not pickup external jpeg includes: openjdk uses an internal
### libjpeg with potentially conflicting defines, which breaks at least
### libjpeg-turbo
post-wrapper:
	${RM} -f ${BUILDLINK_DIR}/include/jconfig.h
	${RM} -f ${BUILDLINK_DIR}/include/jerror.h
	${RM} -f ${BUILDLINK_DIR}/include/jmorecfg.h
	${RM} -f ${BUILDLINK_DIR}/include/jpeglib.h

# Workaround incorrect constant folding of subnormals in javac when the FPU
# does not handle subnormal arithmetic, like on ARM in Flush-to-zero mode.
# These workarounds avoid underflow conditions during the bootstrap so the
# JDK can correctly build itself. Compiling or running programs other than
# openjdk itself on such hardware may still cause unexpected behaviour.
#
COMPARE_SUBNORMAL_CMD=	${AWK} 'BEGIN {print (1E-307*1E-1==0?"yes":"no");exit;}'
BROKEN_IEEE_FLOATS:=	${COMPARE_SUBNORMAL_CMD:sh}
.if !empty(BROKEN_IEEE_FLOATS:Myes)
PKG_HACKS+=		broken-ieee-floats
SUBST_CLASSES+=		fpu
SUBST_STAGE.fpu=	pre-build
SUBST_MESSAGE.fpu=	Broken FPU detected: applying floating point workarounds
SUBST_FILES.fpu=	langtools/src/share/classes/com/sun/tools/javac/jvm/Items.java
SUBST_FILES.fpu+=	langtools/src/share/classes/com/sun/tools/javac/parser/JavacParser.java
SUBST_FILES.fpu+=	jdk/src/share/classes/sun/misc/DoubleConsts.java
SUBST_FILES.fpu+=	jdk/src/share/classes/sun/misc/FloatConsts.java
# {Double,Float}Consts.java: Replace problematic MIN_NORMAL literals with alternative representation
SUBST_SED.fpu=		-e 's|2.2250738585072014E-308|0x1.0p-1022|g'
SUBST_SED.fpu+=		-e 's|1.17549435E-38f|0x1.0p-126f|g'
# JavacParser.java: avoid bogus "fp.number.too.small" error parsing literals representing Double.MIN_VALUE
SUBST_SED.fpu+=		-e 's|n.floatValue() == 0.0f && !isZero(proper)|& \&\& Float.floatToIntBits(n) != 0x1|'
SUBST_SED.fpu+=		-e 's|n.doubleValue() == 0.0d && !isZero(proper)|& \&\& Double.doubleToLongBits(n) != 0x1L|'
# Items.java: Avoid invalid constant folding of literal subnormals to positive zero
SUBST_SED.fpu+=		-e 's|x == 0.0f && 1.0f / x > 0.0f|Float.floatToIntBits(x) == 0x0|g'
SUBST_SED.fpu+=		-e 's|x == 0.0d && 1.0d / x > 0.0d|Double.doubleToLongBits(x) == 0x0L|g'
.endif

.endif
