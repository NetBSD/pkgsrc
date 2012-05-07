# $NetBSD: buildlink3.mk,v 1.4 2012/05/07 01:53:57 dholland Exp $

BUILDLINK_TREE+=	pakchois

.if !defined(PAKCHOIS_BUILDLINK3_MK)
PAKCHOIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pakchois+=	pakchois>=0.4
BUILDLINK_ABI_DEPENDS.pakchois+=	pakchois>=0.4nb1
BUILDLINK_PKGSRCDIR.pakchois?=	../../security/pakchois

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.endif # PAKCHOIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pakchois
