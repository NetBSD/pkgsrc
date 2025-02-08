# $NetBSD: buildlink3.mk,v 1.5 2025/02/08 02:59:57 taca Exp $

BUILDLINK_TREE+=	php83

.if !defined(PHP83_BUILDLINK3_MK)
PHP83_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php83+=	php${PHP_VER}>=8.3.0<8.4
BUILDLINK_ABI_DEPENDS.php83+=	php${PHP_VER}>=8.3.13nb4
BUILDLINK_PKGSRCDIR.php83?=	../../lang/php83
BUILDLINK_INCDIRS.php83+=	${PHP_INCDIR}

pkgbase := php83
.include "../../mk/pkg-build-options.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP83_BUILDLINK3_MK

BUILDLINK_TREE+=	-php83
