# $NetBSD: buildlink2.mk,v 1.2 2002/10/13 09:08:15 jlam Exp $

.if !defined(SUN_JRE14_BUILDLINK2_MK)
SUN_JRE14_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		sun-jre14
BUILDLINK_PKGBASE.sun-jre14?=	sun-jre14
BUILDLINK_DEPENDS.sun-jre14?=	sun-jre14-[0-9]*
BUILDLINK_PKGSRCDIR.sun-jre14?=	../../lang/sun-jre14

BUILDLINK_PREFIX.sun-jre14=	${LOCALBASE}
BUILDLINK_FILES_CMD.sun-jre14= \
	${BUILDLINK_PLIST_CMD.sun-jre14} |				\
		${GREP} '\(include.*/\|lib.*/lib[^/]*$$\)' |		\
		${SED} "s,^,$${pkg_prefix},"

EVAL_PREFIX+=	BUILDLINK_JAVA_PREFIX.sun-jre14=sun-jre14
BUILDLINK_JAVA_PREFIX.sun-jre14_DEFAULT= \
	${BUILDLINK_PREFIX.sun-jre14}/java/sun-1.4.0

UNLIMIT_RESOURCES+=	datasize	# must be at least 131204
BUILDLINK_TARGETS+=	sun-jre14-buildlink

sun-jre14-buildlink: _BUILDLINK_USE

.endif	# SUN_JRE14_BUILDLINK2_MK
