# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/04/11 19:05:55 drochner Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TOTEM_PL_PARSER_BUILDLINK3_MK:=	${TOTEM_PL_PARSER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	totem-pl-parser
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntotem-pl-parser}
BUILDLINK_PACKAGES+=	totem-pl-parser
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}totem-pl-parser

.if ${TOTEM_PL_PARSER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.totem-pl-parser+=	totem-pl-parser>=2.22.1
BUILDLINK_PKGSRCDIR.totem-pl-parser?=	../../multimedia/totem-pl-parser
.endif	# TOTEM_PL_PARSER_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
