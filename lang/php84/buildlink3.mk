# $NetBSD: buildlink3.mk,v 1.4 2026/11/11 11:54:16 wiz Exp $

BUILDLINK_TREE+=	php84

.if !defined(PHP84_BUILDLINK3_MK)
PHP84_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.php84+=	php${PHP_VER}>=8.4.0<8.5
BUILDLINK_ABI_DEPENDS.php84+=	php84>=8.4.27nb1
BUILDLINK_PKGSRCDIR.php84?=	../../lang/php84
BUILDLINK_INCDIRS.php84+=	${PHP_INCDIR}

pkgbase := php84
.include "../../mk/pkg-build-options.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # PHP84_BUILDLINK3_MK

BUILDLINK_TREE+=	-php84
