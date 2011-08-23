# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/08/23 08:50:14 abs Exp $

BUILDLINK_TREE+=	p5-Event

.if !defined(P5_EVENT_BUILDLINK3_MK)
P5_EVENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.p5-Event+=	p5-Event>=1.13
BUILDLINK_PKGSRCDIR.p5-Event?=	../../devel/p5-Event

.include "../../lang/perl5/buildlink3.mk"
.endif # P5_EVENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-p5-Event
