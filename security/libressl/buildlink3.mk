# $NetBSD: buildlink3.mk,v 1.5 2023/04/05 10:58:40 nikita Exp $

BUILDLINK_TREE+=	libressl

.if !defined(LIBRESSL_BUILDLINK3_MK)
LIBRESSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libressl+=	libressl>=3.6.2
BUILDLINK_PKGSRCDIR.libressl?=		../../security/libressl

BUILDLINK_INCDIRS.libressl+=	libressl/include
BUILDLINK_LIBDIRS.libressl+=	libressl/lib
# XXX this overwrites all the other typical values
_PKG_CONFIG_LIBDIR=		${PREFIX}/libressl/lib/pkgconfig
.endif	# LIBRESSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libressl
