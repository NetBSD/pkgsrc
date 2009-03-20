# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:24:03 joerg Exp $

BUILDLINK_TREE+=	pilot-link-libs

.if !defined(PILOT_LINK_LIBS_BUILDLINK3_MK)
PILOT_LINK_LIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pilot-link-libs+=	pilot-link-libs>=0.11.7nb1
BUILDLINK_ABI_DEPENDS.pilot-link-libs+=	pilot-link-libs>=0.12.1
BUILDLINK_PKGSRCDIR.pilot-link-libs?=	../../comms/pilot-link-libs

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.endif # PILOT_LINK_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pilot-link-libs
