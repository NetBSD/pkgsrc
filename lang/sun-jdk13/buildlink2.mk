# $NetBSD: buildlink2.mk,v 1.1 2002/10/13 07:51:37 jlam Exp $

.if !defined(SUN_JDK13_BUILDLINK2_MK)
SUN_JDK13_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		sun-jdk13
BUILDLINK_PKGBASE.sun-jdk13?=	sun-jdk13
BUILDLINK_DEPENDS.sun-jdk13?=	sun-jdk13-[0-9]*
BUILDLINK_PKGSRCDIR.sun-jdk13?=	../../lang/sun-jdk13

BUILDLINK_PREFIX.sun-jdk13=	${LOCALBASE}
BUILDLINK_FILES_CMD.sun-jdk13= \
	${BUILDLINK_PLIST_CMD.sun-jdk13} |				\
		${GREP} '\(include.*/\|lib.*/lib[^/]*$$\)' |		\
		${SED} "s,^,$${pkg_prefix},"

BUILDLINK_CPPFLAGS.sun-jdk13= \
	-I${BUILDLINK_JAVA_PREFIX.sun-jre13}/include			\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre13}/include/linux

.include "../../lang/sun-jre13/buildlink2.mk"

BUILDLINK_TARGETS+=	sun-jdk13-buildlink

sun-jdk13-buildlink: _BUILDLINK_USE

.endif	# SUN_JDK13_BUILDLINK2_MK
