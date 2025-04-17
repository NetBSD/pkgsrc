# $NetBSD: buildlink3.mk,v 1.6 2025/04/17 21:51:22 wiz Exp $

BUILDLINK_TREE+=	php83

.if !defined(PHP83_BUILDLINK3_MK)
PHP83_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php83+=	php${PHP_VER}>=8.3.0<8.4
BUILDLINK_ABI_DEPENDS.php83+=	php83>=8.3.20nb1
BUILDLINK_PKGSRCDIR.php83?=	../../lang/php83
BUILDLINK_INCDIRS.php83+=	${PHP_INCDIR}

pkgbase := php83
.include "../../mk/pkg-build-options.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP83_BUILDLINK3_MK

BUILDLINK_TREE+=	-php83
