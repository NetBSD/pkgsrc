# $NetBSD: buildlink2.mk,v 1.2 2002/10/13 08:19:55 jlam Exp $

.if !defined(SUN_JDK14_BUILDLINK2_MK)
SUN_JDK14_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		sun-jdk14
BUILDLINK_PKGBASE.sun-jdk14?=	sun-jdk14
BUILDLINK_DEPENDS.sun-jdk14?=	sun-jdk14-[0-9]*
BUILDLINK_PKGSRCDIR.sun-jdk14?=	../../lang/sun-jdk14
BUILDLINK_DEPMETHOD.sun-jdk14?=	build

BUILDLINK_PREFIX.sun-jdk14=	${LOCALBASE}
BUILDLINK_FILES_CMD.sun-jdk14= \
	${BUILDLINK_PLIST_CMD.sun-jdk14} |				\
		${GREP} '\(include.*/\|lib.*/lib[^/]*$$\)' |		\
		${SED} "s,^,$${pkg_prefix},"

BUILDLINK_CPPFLAGS.sun-jdk14= \
	-I${BUILDLINK_JAVA_PREFIX.sun-jre14}/include			\
	-I${BUILDLINK_JAVA_PREFIX.sun-jre14}/include/linux

.include "../../lang/sun-jre14/buildlink2.mk"

BUILDLINK_TARGETS+=	sun-jdk14-buildlink

sun-jdk14-buildlink: _BUILDLINK_USE

.endif	# SUN_JDK14_BUILDLINK2_MK
