# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/04/09 11:31:55 grant Exp $
#

.if !defined(P5_NET_GOOGLE_BUILDLINK2_MK)
P5_NET_GOOGLE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			p5-Net-Google
BUILDLINK_DEPENDS.p5-Net-Google?=	p5-Net-Google>=0.61
BUILDLINK_PKGSRCDIR.p5-Net-Google?=	../../net/p5-Net-Google

EVAL_PREFIX+=	BUILDLINK_PREFIX.p5-Net-Google=p5-Net-Google
BUILDLINK_PREFIX.p5-Net-Google_DEFAULT=	${LOCALBASE}

BUILDLINK_TARGETS+=	p5-Net-Google-buildlink

p5-Net-Google-buildlink: _BUILDLINK_USE

.endif	# P5_NET_GOOGLE_BUILDLINK2_MK
