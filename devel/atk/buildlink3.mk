# $NetBSD: buildlink3.mk,v 1.14 2009/03/20 19:24:09 joerg Exp $

BUILDLINK_TREE+=	atk

.if !defined(ATK_BUILDLINK3_MK)
ATK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.atk+=		atk>=1.11.4
BUILDLINK_ABI_DEPENDS.atk+=	atk>=1.11.4
BUILDLINK_PKGSRCDIR.atk?=	../../devel/atk

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # ATK_BUILDLINK3_MK

BUILDLINK_TREE+=	-atk
