# $NetBSD: buildlink2.mk,v 1.3 2004/03/29 05:05:40 jlam Exp $

.if !defined(JA_FREEWNN_BUILDLINK2_MK)
JA_FREEWNN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			ja-freewnn
BUILDLINK_PKGBASE.ja-freewnn?=		ja-FreeWnn-lib
BUILDLINK_DEPENDS.ja-freewnn?=		ja-FreeWnn-lib>=1.10
BUILDLINK_PKGSRCDIR.ja-freewnn?=	../../inputmethod/ja-freewnn-lib
BUILDLINK_DEPMETHOD.ja-freewnn?=	build

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

BUILDLINK_TARGETS+=	ja-freewnn-buildlink

ja-freewnn-buildlink: _BUILDLINK_USE

.endif	# JA_FREEWNN_BUILDLINK2_MK
