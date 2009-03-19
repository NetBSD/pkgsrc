# $NetBSD: buildlink3.mk,v 1.27 2009/03/19 12:02:09 drochner Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
EVOLUTION_DATA_SERVER_BUILDLINK3_MK:=	${EVOLUTION_DATA_SERVER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	evolution-data-server
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nevolution-data-server}
BUILDLINK_PACKAGES+=	evolution-data-server
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}evolution-data-server

.if !empty(EVOLUTION_DATA_SERVER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.evolution-data-server+=	evolution-data-server>=1.8.0
BUILDLINK_ABI_DEPENDS.evolution-data-server?=	evolution-data-server>=2.22.3nb1
BUILDLINK_PKGSRCDIR.evolution-data-server?=	../../mail/evolution-data-server

PRINT_PLIST_AWK+=/^@dirrm lib\/evolution-data-server-1.2\/extensions$$/ \
		{ print "@comment in evolution-data-server: " $$0; next }
PRINT_PLIST_AWK+=/^@dirrm lib\/evolution-data-server-1.2\/camel-providers$$/ \
		{ print "@comment in evolution-data-server: " $$0; next }
PRINT_PLIST_AWK+=/^@dirrm lib\/evolution-data-server-1.2$$/ \
		{ print "@comment in evolution-data-server: " $$0; next }
.endif	# EVOLUTION_DATA_SERVER_BUILDLINK3_MK

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
