# $NetBSD: buildlink2.mk,v 1.3 2002/09/11 21:29:28 wiz Exp $

.if !defined(LIBSIGCXX_BUILDLINK2_MK)
LIBSIGCXX_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libsigcxx
BUILDLINK_DEPENDS.libsigcxx?=	libsigc++>=1.0.4
BUILDLINK_PKGSRCDIR.libsigcxx?=	../../devel/libsigc++

EVAL_PREFIX+=			BUILDLINK_PREFIX.libsigcxx=libsigc++
BUILDLINK_PREFIX.libsigcxx_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libsigcxx=	include/sigc++-1.0/sigc++/*
BUILDLINK_FILES.libsigcxx+=	lib/sigc++-1.0/include/sigc++config.h
BUILDLINK_FILES.libsigcxx+=	lib/libsigc.*

BUILDLINK_TARGETS+=	libsigcxx-buildlink

libsigcxx-buildlink: _BUILDLINK_USE

.endif	# LIBSIGCXX_BUILDLINK2_MK
