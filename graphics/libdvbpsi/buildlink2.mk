# $NetBSD: buildlink2.mk,v 1.2 2003/11/17 00:45:58 recht Exp $

.if !defined(LIBDVBPSI_BUILDLINK2_MK)
LIBDVBPSI_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libdvbpsi
BUILDLINK_DEPENDS.libdvbpsi?=		libdvbpsi>=0.1.3
BUILDLINK_PKGSRCDIR.libdvbpsi?=	../../graphics/libdvbpsi

EVAL_PREFIX+=		BUILDLINK_PREFIX.libdvbpsi=libdvbpsi
BUILDLINK_PREFIX.libdvbpsi=	${LOCALBASE}
BUILDLINK_FILES.libdvbpsi=	include/dvbpsi/*
BUILDLINK_FILES.libdvbpsi+=	lib/libdvbpsi.*

BUILDLINK_TARGETS+=	libdvbpsi-buildlink

libdvbpsi-buildlink: _BUILDLINK_USE

.endif	# LIBDVBPSI_BUILDLINK2_MK
