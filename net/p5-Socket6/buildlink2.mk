# $NetBSD: buildlink2.mk,v 1.1 2003/12/17 14:21:39 martti Exp $
#
# This Makefile fragment is included by packages that use p5-Socket6.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(P5_SOCKET6_BUILDLINK2_MK)
P5_SOCKET6_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			p5-Socket6
BUILDLINK_DEPENDS.p5-Socket6?=		p5-Socket6>=0.12
BUILDLINK_PKGSRCDIR.p5-Socket6?=		../../net/p5-Socket6

EVAL_PREFIX+=	BUILDLINK_PREFIX.p5-Socket6=p5-Socket6
BUILDLINK_PREFIX.p5-Socket6_DEFAULT=	${LOCALBASE}

BUILDLINK_TARGETS+=	p5-Socket6-buildlink

p5-Socket6-buildlink: _BUILDLINK_USE

.endif	# P5_SOCKET6_BUILDLINK2_MK
