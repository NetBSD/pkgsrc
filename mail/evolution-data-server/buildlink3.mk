# $NetBSD: buildlink3.mk,v 1.8 2005/03/22 16:18:07 jmmv Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
EVOLUTION_DATA_SERVER_BUILDLINK3_MK:=	${EVOLUTION_DATA_SERVER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	evolution-data-server
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nevolution-data-server}
BUILDLINK_PACKAGES+=	evolution-data-server

.if !empty(EVOLUTION_DATA_SERVER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.evolution-data-server+=	evolution-data-server>=1.2.0
BUILDLINK_PKGSRCDIR.evolution-data-server?=	../../mail/evolution-data-server
.endif	# EVOLUTION_DATA_SERVER_BUILDLINK3_MK

PRINT_PLIST_AWK+=/^@dirrm lib\/evolution-data-server-1.2\/extensions$$/ \
		{ print "@comment in evolution-data-server: " $$0; next }
PRINT_PLIST_AWK+=/^@dirrm lib\/evolution-data-server-1.2\/camel-providers$$/ \
		{ print "@comment in evolution-data-server: " $$0; next }
PRINT_PLIST_AWK+=/^@dirrm lib\/evolution-data-server-1.2$$/ \
		{ print "@comment in evolution-data-server: " $$0; next }

.include "../../databases/openldap/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../net/libsoup-devel/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
