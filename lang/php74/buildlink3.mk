# $NetBSD: buildlink3.mk,v 1.14 2025/02/08 02:58:55 taca Exp $

BUILDLINK_TREE+=	php74

.if !defined(PHP74_BUILDLINK3_MK)
PHP74_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php74+=	php${PHP_VER}>=7.4.0<7.5
BUILDLINK_ABI_DEPENDS.php74+=	php${PHP_VER}>=7.4.33
BUILDLINK_PKGSRCDIR.php74?=	../../lang/php74
BUILDLINK_INCDIRS.php74+=	${PHP_INCDIR}

pkgbase := php74
.include "../../mk/pkg-build-options.mk"

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP74_BUILDLINK3_MK

BUILDLINK_TREE+=	-php74
