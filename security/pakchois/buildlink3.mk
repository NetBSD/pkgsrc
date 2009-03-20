# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:21 joerg Exp $

BUILDLINK_TREE+=	pakchois

.if !defined(PAKCHOIS_BUILDLINK3_MK)
PAKCHOIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pakchois+=	pakchois>=0.4
BUILDLINK_PKGSRCDIR.pakchois?=	../../security/pakchois

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.endif # PAKCHOIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pakchois
