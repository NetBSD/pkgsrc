# $NetBSD: hacks.mk,v 1.4 2016/03/08 20:03:52 tnn Exp $

.if !defined(OPENJDK7_HACKS_MK)
OPENJDK7_HACKS_MK=	# empty

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

.if !empty(MACHINE_PLATFORM:MNetBSD-*-*arm*)
PKG_HACKS+=		broken-ieee-floats
SUBST_CLASSES+=		fpu
SUBST_STAGE.fpu=	pre-build
SUBST_MESSAGE.fpu=	Broken FPU detected: applying floating point workarounds
SUBST_FILES.fpu=	langtools/src/share/classes/com/sun/tools/javac/jvm/Items.java
SUBST_FILES.fpu+=	langtools/src/share/classes/com/sun/tools/javac/parser/JavacParser.java
SUBST_FILES.fpu+=	jdk/src/share/classes/sun/misc/DoubleConsts.java
SUBST_FILES.fpu+=	jdk/src/share/classes/sun/misc/FloatConsts.java
SUBST_FILES.fpu+=	jdk/src/share/classes/java/lang/Double.java
SUBST_FILES.fpu+=	jdk/src/share/classes/java/lang/Float.java
# Double{,Consts}.java: Replace problematic literals with binary representation
SUBST_SED.fpu=		-e 's|2.2250738585072014e-308d*|Double.longBitsToDouble(0x10000000000000L)|ig'	# MIN_NORMAL
SUBST_SED.fpu+=		-e 's|0x1.0p-1022d*|Double.longBitsToDouble(0x10000000000000L)|ig'		# MIN_NORMAL
SUBST_SED.fpu+=		-e 's|4.9e-324d*|Double.longBitsToDouble(0x1L)|ig'				# MIN_VALUE
SUBST_SED.fpu+=		-e 's|0x0.0000000000001p-1022d*|Double.longBitsToDouble(0x1L)|ig'		# MIN_VALUE
# Float{,Consts}.java: Replace problematic literals with binary representation
SUBST_SED.fpu+=		-e 's|1.17549435e-38f*|Float.intBitsToFloat(0x800000)|ig'	# MIN_NORMAL
SUBST_SED.fpu+=		-e 's|0x1.0p-126f*|Float.intBitsToFloat(0x800000)|ig'		# MIN_NORMAL
SUBST_SED.fpu+=		-e 's|1.4e-45f*|Float.intBitsToFloat(0x1)|ig'			# MIN_VALUE
SUBST_SED.fpu+=		-e 's|0x0.000002P-126f*|Float.intBitsToFloat(0x1)|ig'		# MIN_VALUE
# JavacParser.java: avoid bogus "fp.number.too.small" error parsing literals representing Double.MIN_VALUE
SUBST_SED.fpu+=		-e 's|n.floatValue() == 0.0f && !isZero(proper)|& \&\& Float.floatToIntBits(n) != 0x1|'
SUBST_SED.fpu+=		-e 's|n.doubleValue() == 0.0d && !isZero(proper)|& \&\& Double.doubleToLongBits(n) != 0x1L|'
# Items.java: Avoid invalid constant folding of literal subnormals to positive zero
SUBST_SED.fpu+=		-e 's|x == 0.0f && 1.0f / x > 0.0f|Float.floatToIntBits(x) == 0x0|g'
SUBST_SED.fpu+=		-e 's|x == 0.0d && 1.0d / x > 0.0d|Double.doubleToLongBits(x) == 0x0L|g'
.endif

.endif
