# $NetBSD: buildlink3.mk,v 1.1 2016/06/26 21:36:06 wiz Exp $

BUILDLINK_TREE+=	libressl

.if !defined(LIBRESSL_BUILDLINK3_MK)
LIBRESSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libressl+=	libressl>=2.2.6
BUILDLINK_PKGSRCDIR.libressl?=	../../security/libressl

BUILDLINK_PASSTHRU_DIRS+=	libressl/include
BUILDLINK_PASSTHRU_DIRS+=	libressl/lib
CPPFLAGS+=			-I${PREFIX}/libressl/include
LDFLAGS+=			${COMPILER_RPATH_FLAG}${PREFIX}/libressl/lib -L${PREFIX}/libressl/lib
.endif	# LIBRESSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libressl
