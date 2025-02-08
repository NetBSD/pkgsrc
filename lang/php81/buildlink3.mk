# $NetBSD: buildlink3.mk,v 1.10 2025/02/08 02:59:29 taca Exp $

BUILDLINK_TREE+=	php81

.if !defined(PHP81_BUILDLINK3_MK)
PHP81_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php81+=	php${PHP_VER}>=8.1.0<8.2
BUILDLINK_ABI_DEPENDS.php81+=	php${PHP_VER}>=8.1.12
BUILDLINK_PKGSRCDIR.php81?=	../../lang/php81
BUILDLINK_INCDIRS.php74+=	${PHP_INCDIR}

pkgbase := php81
.include "../../mk/pkg-build-options.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP81_BUILDLINK3_MK

BUILDLINK_TREE+=	-php81
