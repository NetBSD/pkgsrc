# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:11 joerg Exp $
#

BUILDLINK_TREE+=	confuse

.if !defined(CONFUSE_BUILDLINK3_MK)
CONFUSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.confuse+=	confuse>=2.5
BUILDLINK_PKGSRCDIR.confuse?=	../../devel/confuse
.endif # CONFUSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-confuse
