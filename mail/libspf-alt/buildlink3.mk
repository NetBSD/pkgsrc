# $NetBSD: buildlink3.mk,v 1.11 2011/04/22 13:41:56 obache Exp $

BUILDLINK_TREE+=	libspf_alt

.if !defined(LIBSPF_ALT_BUILDLINK3_MK)
LIBSPF_ALT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libspf_alt+=	libspf_alt>=0.4.0nb1
BUILDLINK_ABI_DEPENDS.libspf_alt+=	libspf_alt>=0.4.0nb5
BUILDLINK_PKGSRCDIR.libspf_alt?=	../../mail/libspf-alt

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/resolv.buildlink3.mk"
.endif # LIBSPF_ALT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libspf_alt
