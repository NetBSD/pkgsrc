# $NetBSD: buildlink2.mk,v 1.1.2.3 2002/06/21 23:00:36 jlam Exp $

.if !defined(SOCKS5_BUILDLINK2_MK)
SOCKS5_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		socks5
BUILDLINK_DEPENDS.socks5?=	socks5>=1.0.2
BUILDLINK_PKGSRCDIR.socks5?=	../../net/socks5

EVAL_PREFIX+=	BUILDLINK_PREFIX.socks5=socks5
BUILDLINK_PREFIX.socks5_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.socks5=		include/socks.h
BUILDLINK_FILES.socks5+=	lib/libsocks5.a
BUILDLINK_FILES.socks5+=	lib/libsocks5_sh.*

BUILDLINK_TARGETS+=		socks5-buildlink

socks5-buildlink: _BUILDLINK_USE

.endif	# SOCKS5_BUILDLINK2_MK
