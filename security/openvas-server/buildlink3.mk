# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:21 joerg Exp $

BUILDLINK_TREE+=	openvas-server

.if !defined(OPENVAS_SERVER_BUILDLINK3_MK)
OPENVAS_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openvas-server+=	openvas-server>=2.0.0
BUILDLINK_PKGSRCDIR.openvas-server?=	../../security/openvas-server
.endif # OPENVAS_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-openvas-server
