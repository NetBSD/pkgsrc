# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/04/01 18:40:51 jmmv Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
EVOLUTION_DATA_SERVER_BUILDLINK3_MK:=	${EVOLUTION_DATA_SERVER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	evolution-data-server
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nevolution-data-server}
BUILDLINK_PACKAGES+=	evolution-data-server

.if !empty(EVOLUTION_DATA_SERVER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.evolution-data-server+=	evolution-data-server>=0.0.90
BUILDLINK_PKGSRCDIR.evolution-data-server?=	../../local/evolution-data-server

.include "../../databases/db4/buildlink3.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.endif	# EVOLUTION_DATA_SERVER_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
