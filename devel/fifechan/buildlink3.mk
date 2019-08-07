# $NetBSD: buildlink3.mk,v 1.1 2019/08/07 11:44:40 nia Exp $

BUILDLINK_TREE+=	fifechan

.if !defined(FIFECHAN_BUILDLINK3_MK)
FIFECHAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fifechan+=	fifechan>=0.1.5
BUILDLINK_PKGSRCDIR.fifechan?=		../../devel/fifechan
.endif	# FIFECHAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-fifechan
