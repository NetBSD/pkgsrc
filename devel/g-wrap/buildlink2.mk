# $NetBSD: buildlink2.mk,v 1.7 2003/07/13 13:51:07 wiz Exp $

.if !defined(G_WRAP_BUILDLINK2_MK)
G_WRAP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		g-wrap
BUILDLINK_DEPENDS.g-wrap?=	g-wrap>=1.3.4nb3
BUILDLINK_PKGSRCDIR.g-wrap?=	../../devel/g-wrap

EVAL_PREFIX+=	BUILDLINK_PREFIX.g-wrap=g-wrap
BUILDLINK_PREFIX.g-wrap_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.g-wrap=		include/g-wrap/*
BUILDLINK_FILES.g-wrap+=        lib/libgw-*
BUILDLINK_FILES.g-wrap+=        lib/libgwrap-*

.include "../../lang/guile14/buildlink2.mk"

BUILDLINK_TARGETS+=	g-wrap-buildlink

g-wrap-buildlink: _BUILDLINK_USE

.endif	# G_WRAP_BUILDLINK2_MK
