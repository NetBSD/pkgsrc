# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:24:55 joerg Exp $

BUILDLINK_TREE+=	libspf_alt

.if !defined(LIBSPF_ALT_BUILDLINK3_MK)
LIBSPF_ALT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspf_alt+=	libspf_alt>=0.4.0nb1
BUILDLINK_ABI_DEPENDS.libspf_alt+=	libspf_alt>=0.4.0nb3
BUILDLINK_PKGSRCDIR.libspf_alt?=	../../mail/libspf-alt

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/resolv.buildlink3.mk"
.endif # LIBSPF_ALT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspf_alt
