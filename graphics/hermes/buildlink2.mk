# $NetBSD: buildlink2.mk,v 1.3 2004/03/29 05:05:39 jlam Exp $

.if !defined(HERMES_BUILDLINK2_MK)
HERMES_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		hermes
BUILDLINK_PKGBASE.hermes?=	Hermes
BUILDLINK_DEPENDS.hermes?=	Hermes>=1.3.2
BUILDLINK_PKGSRCDIR.hermes?=	../../graphics/hermes

EVAL_PREFIX+=			BUILDLINK_PREFIX.hermes=Hermes
BUILDLINK_PREFIX.hermes_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.hermes=		include/Hermes/*
BUILDLINK_FILES.hermes+=	lib/libHermes.*

BUILDLINK_TARGETS+=	hermes-buildlink

hermes-buildlink: _BUILDLINK_USE

.endif	# HERMES_BUILDLINK2_MK
