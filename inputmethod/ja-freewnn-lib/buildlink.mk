# $NetBSD: buildlink.mk,v 1.2 2002/08/25 19:22:57 jlam Exp $
#
# This Makefile fragment is included by packages that use FreeWnn.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define BUILDLINK_DEPENDS.ja-freewnn to the dependency pattern
#     for the version of FreeWnn desired.
# (2) Include this Makefile fragment in the package Makefile,
# (3) Add ${BUILDLINK_DIR}/include to the front of the C preprocessor's header
#     search path, and
# (4) Add ${BUILDLINK_DIR}/lib to the front of the linker's library search
#     path.

.if !defined(JA_FREEWNN_BUILDLINK_MK)
JA_FREEWNN_BUILDLINK_MK=	# defined

.include "../../mk/bsd.buildlink.mk"

BUILDLINK_DEPENDS.ja-freewnn?=	ja-FreeWnn-lib>=1.10
DEPENDS+=	${BUILDLINK_DEPENDS.ja-freewnn}:../../inputmethod/ja-freewnn-lib

EVAL_PREFIX+=			BUILDLINK_PREFIX.ja-freewnn=ja-FreeWnn-lib
BUILDLINK_PREFIX.ja-freewnn_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ja-freewnn=		include/wnn/commonhd.h
BUILDLINK_FILES.ja-freewnn+=		include/wnn/config.h
BUILDLINK_FILES.ja-freewnn+=		include/wnn/cplib.h
BUILDLINK_FILES.ja-freewnn+=		include/wnn/jlib.h
BUILDLINK_FILES.ja-freewnn+=		include/wnn/jllib.h
BUILDLINK_FILES.ja-freewnn+=		include/wnn/jslib.h
BUILDLINK_FILES.ja-freewnn+=		include/wnn/msg.h
BUILDLINK_FILES.ja-freewnn+=		include/wnn/rk_spclval.h
BUILDLINK_FILES.ja-freewnn+=		include/wnn/wnnerror.h
BUILDLINK_FILES.ja-freewnn+=		lib/libjd.a
BUILDLINK_FILES.ja-freewnn+=		lib/libwnn.a

BUILDLINK_TARGETS.ja-freewnn=	ja-freewnn-buildlink
BUILDLINK_TARGETS+=		${BUILDLINK_TARGETS.ja-freewnn}

pre-configure: ${BUILDLINK_TARGETS.ja-freewnn}
ja-freewnn-buildlink: _BUILDLINK_USE

.endif	# JA_FREEWNN_BUILDLINK_MK
