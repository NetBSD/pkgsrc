# $NetBSD: buildlink3.mk,v 1.25 2009/06/14 22:58:04 joerg Exp $

BUILDLINK_TREE+=	evolution

.if !defined(EVOLUTION_BUILDLINK3_MK)
EVOLUTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evolution+=	evolution>=2.8.0
BUILDLINK_ABI_DEPENDS.evolution?=	evolution>=2.22.3.1nb1
BUILDLINK_PKGSRCDIR.evolution?=	../../mail/evolution

.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../www/gtkhtml314/buildlink3.mk"
.endif # EVOLUTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-evolution
