# $NetBSD: buildlink3.mk,v 1.15 2022/10/26 10:31:03 wiz Exp $
#

BUILDLINK_TREE+=	obby

.if !defined(OBBY_BUILDLINK3_MK)
OBBY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.obby+=	obby>=0.4.4
BUILDLINK_ABI_DEPENDS.obby+=	obby>=0.4.8nb9
BUILDLINK_PKGSRCDIR.obby?=	../../editors/obby

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../net/net6/buildlink3.mk"
.endif # OBBY_BUILDLINK3_MK

BUILDLINK_TREE+=	-obby
