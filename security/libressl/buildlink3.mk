# $NetBSD: buildlink3.mk,v 1.4 2020/11/26 15:49:58 schmonz Exp $

BUILDLINK_TREE+=	libressl

.if !defined(LIBRESSL_BUILDLINK3_MK)
LIBRESSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libressl+=	libressl>=2.7.4nb1
BUILDLINK_PKGSRCDIR.libressl?=		../../security/libressl

BUILDLINK_INCDIRS.libressl+=	libressl/include
BUILDLINK_LIBDIRS.libressl+=	libressl/lib
# XXX this overwrites all the other typical values
_PKG_CONFIG_LIBDIR=		${PREFIX}/libressl/lib/pkgconfig
.endif	# LIBRESSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libressl
