# $NetBSD: buildlink2.mk,v 1.1 2002/09/24 10:32:42 jlam Exp $

.if !defined(G_WRAP_BUILDLINK2_MK)
G_WRAP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		g-wrap
BUILDLINK_DEPENDS.g-wrap?=	g-wrap>=1.2.1
BUILDLINK_PKGSRCDIR.g-wrap?=	../../devel/g-wrap

EVAL_PREFIX+=	BUILDLINK_PREFIX.g-wrap=g-wrap
BUILDLINK_PREFIX.g-wrap_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.g-wrap+=	include/g-wrap-runtime-guile.h
BUILDLINK_FILES.g-wrap+=	lib/libg-wrap-runtime-guile.*

.include "../../lang/guile/buildlink2.mk"

BUILDLINK_TARGETS+=	g-wrap-buildlink

g-wrap-buildlink: _BUILDLINK_USE

.endif	# G_WRAP_BUILDLINK2_MK
