# $NetBSD: buildlink3.mk,v 1.73 2020/03/08 16:47:53 wiz Exp $

BUILDLINK_TREE+=	evolution-data-server

.if !defined(EVOLUTION_DATA_SERVER_BUILDLINK3_MK)
EVOLUTION_DATA_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evolution-data-server+=	evolution-data-server>=3.35.1
BUILDLINK_ABI_DEPENDS.evolution-data-server?=	evolution-data-server>=3.35.1nb3
BUILDLINK_PKGSRCDIR.evolution-data-server?=	../../mail/evolution-data-server

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# EVOLUTION_DATA_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-evolution-data-server
