# $NetBSD: buildlink2.mk,v 1.1 2002/10/13 07:51:39 jlam Exp $

.if !defined(SUN_JRE13_BUILDLINK2_MK)
SUN_JRE13_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		sun-jre13
BUILDLINK_PKGBASE.sun-jre13?=	sun-jre13
BUILDLINK_DEPENDS.sun-jre13?=	sun-jre13-[0-9]*
BUILDLINK_PKGSRCDIR.sun-jre13?=	../../lang/sun-jre13

BUILDLINK_PREFIX.sun-jre13=	${LOCALBASE}
BUILDLINK_FILES_CMD.sun-jre13= \
	${BUILDLINK_PLIST_CMD.sun-jre13} |				\
		${GREP} '\(include.*/\|lib.*/lib[^/]*$$\)' |		\
		${SED} "s,^,$${pkg_prefix},"

EVAL_PREFIX+=	BUILDLINK_JAVA_PREFIX.sun-jre13=sun-jre13
BUILDLINK_JAVA_PREFIX.sun-jre13_DEFAULT= \
	${BUILDLINK_PREFIX.sun-jre13}/java/sun-1.3.1

BUILDLINK_TARGETS+=	sun-jre13-buildlink

sun-jre13-buildlink: _BUILDLINK_USE

.endif	# SUN_JRE13_BUILDLINK2_MK
