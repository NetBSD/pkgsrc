# $NetBSD: buildlink3.mk,v 1.29 2009/06/14 22:58:04 joerg Exp $

BUILDLINK_TREE+=	evolution-data-server

.if !defined(EVOLUTION_DATA_SERVER_BUILDLINK3_MK)
EVOLUTION_DATA_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evolution-data-server+=	evolution-data-server>=1.8.0
BUILDLINK_ABI_DEPENDS.evolution-data-server?=	evolution-data-server>=2.22.3nb1
BUILDLINK_PKGSRCDIR.evolution-data-server?=	../../mail/evolution-data-server

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.endif # EVOLUTION_DATA_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-evolution-data-server
