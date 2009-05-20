# $NetBSD: buildlink3.mk,v 1.11 2009/05/20 00:58:09 wiz Exp $

BUILDLINK_TREE+=	pilot-link-libs

.if !defined(PILOT_LINK_LIBS_BUILDLINK3_MK)
PILOT_LINK_LIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pilot-link-libs+=	pilot-link-libs>=0.11.7nb1
BUILDLINK_ABI_DEPENDS.pilot-link-libs+=	pilot-link-libs>=0.12.3
BUILDLINK_PKGSRCDIR.pilot-link-libs?=	../../comms/pilot-link-libs

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.endif # PILOT_LINK_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pilot-link-libs
