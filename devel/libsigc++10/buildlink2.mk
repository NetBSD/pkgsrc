# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/03/01 11:47:22 jmmv Exp $

.if !defined(LIBSIGCXX10_BUILDLINK2_MK)
LIBSIGCXX10_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		libsigcxx10
BUILDLINK_DEPENDS.libsigcxx10?=	libsigc++10>=1.0.4
BUILDLINK_PKGSRCDIR.libsigcxx10?=	../../devel/libsigc++10

EVAL_PREFIX+=			BUILDLINK_PREFIX.libsigcxx10=libsigc++10
BUILDLINK_PREFIX.libsigcxx10_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libsigcxx10=	include/sigc++-1.0/sigc++/*
BUILDLINK_FILES.libsigcxx10+=	lib/sigc++-1.0/include/sigc++config.h
BUILDLINK_FILES.libsigcxx10+=	lib/libsigc.*

.include "../../mk/pthread.buildlink2.mk"

BUILDLINK_TARGETS+=	libsigcxx10-buildlink

libsigcxx10-buildlink: _BUILDLINK_USE

.endif	# LIBSIGCXX10_BUILDLINK2_MK
