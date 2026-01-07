# $NetBSD: buildlink3.mk,v 1.10 2026/01/07 08:47:40 wiz Exp $

BUILDLINK_TREE+=	php82

.if !defined(PHP82_BUILDLINK3_MK)
PHP82_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php82+=	php${PHP_VER}>=8.2.0<8.3
BUILDLINK_ABI_DEPENDS.php82+=	php82>=8.2.30nb1
BUILDLINK_PKGSRCDIR.php82?=	../../lang/php82
BUILDLINK_INCDIRS.php82+=	${PHP_INCDIR}

pkgbase := php82
.include "../../mk/pkg-build-options.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP82_BUILDLINK3_MK

BUILDLINK_TREE+=	-php82
