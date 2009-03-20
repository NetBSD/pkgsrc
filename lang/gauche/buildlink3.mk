# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:24:49 joerg Exp $

BUILDLINK_TREE+=	Gauche

.if !defined(GAUCHE_BUILDLINK3_MK)
GAUCHE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Gauche+=	Gauche>=0.8.1
BUILDLINK_PKGSRCDIR.Gauche?=	../../lang/gauche

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.endif # GAUCHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-Gauche
