# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/10/09 13:11:18 jdolecek Exp $

BUILDLINK_DEPTH:=               ${BUILDLINK_DEPTH}+
PHP_PDO_BUILDLINK3_MK:=    ${PHP_PDO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=     php-pdo
.endif

BUILDLINK_PACKAGES:=    ${BUILDLINK_PACKAGES:Nphp-pdo}
BUILDLINK_PACKAGES+=    php-pdo

.if !empty(PHP_PDO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.php-pdo+=        php-pdo-*.1.0RC1
BUILDLINK_PKGSRCDIR.php-pdo?=      ../../databases/php-pdo
BUILDLINK_INCDIRS.php-pdo?=        include/php/ext/pdo
.endif  # PHP_PDO_BUILDLINK3_MK


.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
