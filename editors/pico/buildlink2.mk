# $NetBSD: buildlink2.mk,v 1.3 2003/07/13 13:51:35 wiz Exp $

.if !defined(PICO_BUILDLINK2_MK)
PICO_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		pico
BUILDLINK_DEPENDS.pico?=	pico>=4.4nb2
BUILDLINK_PKGSRCDIR.pico?=	../../editors/pico

EVAL_PREFIX+=	BUILDLINK_PREFIX.pico=pico
BUILDLINK_PREFIX.pico_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pico+=	include/pico/*
BUILDLINK_FILES.pico+=	lib/libpico.*

BUILDLINK_TARGETS+=	pico-buildlink

pico-buildlink: _BUILDLINK_USE

.endif	# PICO_BUILDLINK2_MK
