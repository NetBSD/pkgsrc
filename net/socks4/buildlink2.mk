# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 18:39:36 jlam Exp $

.if !defined(SOCKS4_BUILDLINK2_MK)
SOCKS4_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		socks4
BUILDLINK_DEPENDS.socks4?=	socks4>=2.2
BUILDLINK_PKGSRCDIR.socks4?=	../../net/socks4

EVAL_PREFIX+=	BUILDLINK_PREFIX.socks4=socks4
BUILDLINK_PREFIX.socks4_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.socks4=		lib/libsocks4.*
BUILDLINK_TRANSFORM+=		l:socks:socks4

BUILDLINK_TARGETS+=		socks4-buildlink

socks4-buildlink: _BUILDLINK_USE

.endif	# SOCKS4_BUILDLINK2_MK
