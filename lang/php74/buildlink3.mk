# $NetBSD: buildlink3.mk,v 1.15 2025/04/17 21:51:22 wiz Exp $

BUILDLINK_TREE+=	php74

.if !defined(PHP74_BUILDLINK3_MK)
PHP74_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php74+=	php${PHP_VER}>=7.4.0<7.5
BUILDLINK_ABI_DEPENDS.php74+=	php74>=7.4.33nb1
BUILDLINK_PKGSRCDIR.php74?=	../../lang/php74
BUILDLINK_INCDIRS.php74+=	${PHP_INCDIR}

pkgbase := php74
.include "../../mk/pkg-build-options.mk"

.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP74_BUILDLINK3_MK

BUILDLINK_TREE+=	-php74
