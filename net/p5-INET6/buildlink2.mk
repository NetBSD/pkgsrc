# $NetBSD: buildlink2.mk,v 1.1 2003/12/17 14:21:45 martti Exp $
#
# This Makefile fragment is included by packages that use p5-INET6.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(P5_INET6_BUILDLINK2_MK)
P5_INET6_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			p5-INET6
BUILDLINK_DEPENDS.p5-INET6?=		p5-INET6>=2.00
BUILDLINK_PKGSRCDIR.p5-INET6?=		../../net/p5-INET6

EVAL_PREFIX+=	BUILDLINK_PREFIX.p5-INET6=p5-INET6
BUILDLINK_PREFIX.p5-INET6_DEFAULT=	${LOCALBASE}

BUILDLINK_TARGETS+=	p5-INET6-buildlink

p5-INET6-buildlink: _BUILDLINK_USE

.endif	# P5_INET6_BUILDLINK2_MK
