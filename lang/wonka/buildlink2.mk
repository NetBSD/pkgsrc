# $NetBSD: buildlink2.mk,v 1.2 2004/07/01 00:54:25 wiz Exp $

.if !defined(WONKA_BUILDLINK2_MK)
WONKA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		wonka
BUILDLINK_PKGBASE.wonka?=	wonka
BUILDLINK_DEPENDS.wonka?=	wonka-[0-9]*
BUILDLINK_PKGSRCDIR.wonka?=	../../lang/wonka

BUILDLINK_PREFIX.wonka=	${LOCALBASE}
BUILDLINK_FILES_CMD.wonka= \
	${BUILDLINK_PLIST_CMD.wonka} |					\
		${GREP} '\(include.*/\|lib.*/lib[^/]*$$\)' |		\
		${SED} "s,^,$${pkg_prefix},"

EVAL_PREFIX+=	BUILDLINK_JAVA_PREFIX.wonka=wonka
BUILDLINK_JAVA_PREFIX.wonka_DEFAULT= \
	${BUILDLINK_PREFIX.wonka}/java/wonka

BUILDLINK_TARGETS+=	wonka-buildlink

wonka-buildlink: _BUILDLINK_USE

.endif	# WONKA_BUILDLINK2_MK
