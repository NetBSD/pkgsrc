# $NetBSD: buildlink3.mk,v 1.5 2019/11/23 08:45:45 mef Exp $

BUILDLINK_TREE+=	samba

.if !defined(SAMBA_BUILDLINK3_MK)
SAMBA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.samba+=	samba>=4.9.4
BUILDLINK_ABI_DEPENDS.samba?=	samba>=4.11.2nb1
BUILDLINK_PKGSRCDIR.samba?=	../../net/samba4

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/ldb/buildlink3.mk"
.include "../../devel/cmocka/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/talloc/buildlink3.mk"
.include "../../devel/tevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.endif	# SAMBA_BUILDLINK3_MK

BUILDLINK_TREE+=	-samba
