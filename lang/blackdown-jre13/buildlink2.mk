# $NetBSD: buildlink2.mk,v 1.1 2002/10/13 07:51:39 jlam Exp $

.if !defined(BLACKDOWN_JRE13_BUILDLINK2_MK)
BLACKDOWN_JRE13_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			blackdown-jre13
BUILDLINK_PKGBASE.blackdown-jre13?=	blackdown-jre13
BUILDLINK_DEPENDS.blackdown-jre13?=	blackdown-jre13-[0-9]*
BUILDLINK_PKGSRCDIR.blackdown-jre13?=	../../lang/blackdown-jre13

BUILDLINK_PREFIX.blackdown-jre13=	${LOCALBASE}
BUILDLINK_FILES_CMD.blackdown-jre13= \
	${BUILDLINK_PLIST_CMD.blackdown-jre13} |			\
		${GREP} '\(include.*/\|lib.*/lib[^/]*$$\)' |		\
		${SED} "s,^,$${pkg_prefix},"

EVAL_PREFIX+=	BUILDLINK_JAVA_PREFIX.blackdown-jre13=blackdown-jre13
BUILDLINK_JAVA_PREFIX.blackdown-jre13_DEFAULT= \
	${BUILDLINK_PREFIX.blackdown-jre13}/java/sun-1.3.1

BUILDLINK_TARGETS+=	blackdown-jre13-buildlink

blackdown-jre13-buildlink: _BUILDLINK_USE

.endif	# BLACKDOWN_JRE13_BUILDLINK2_MK
