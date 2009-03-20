# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:24:19 joerg Exp $

BUILDLINK_TREE+=	libidn

.if !defined(LIBIDN_BUILDLINK3_MK)
LIBIDN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libidn+=	libidn>=0.4.6
BUILDLINK_ABI_DEPENDS.libidn+=	libidn>=0.6.1nb1
BUILDLINK_PKGSRCDIR.libidn?=	../../devel/libidn

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.endif # LIBIDN_BUILDLINK3_MK

BUILDLINK_TREE+=	-libidn
