# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:14 jlam Exp $

.if !defined(LIBSIGCXX_BUILDLINK2_MK)
LIBSIGCXX_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libsigcxx
BUILDLINK_DEPENDS.libsigcxx?=	libsigc++>=0.4
BUILDLINK_PKGSRCDIR.libsigcxx?=	../../devel/libsigc++

EVAL_PREFIX+=			BUILDLINK_PREFIX.libsigcxx=libsigc++
BUILDLINK_PREFIX.libsigcxx_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libsigcxx=	include/sigc++/*
BUILDLINK_FILES.libsigcxx+=	lib/sigc++/include/sigc++config.h
BUILDLINK_FILES.libsigcxx+=	lib/libsigc.*

BUILDLINK_TARGETS+=	libsigcxx-buildlink

libsigcxx-buildlink: _BUILDLINK_USE

.endif	# LIBSIGCXX_BUILDLINK2_MK
