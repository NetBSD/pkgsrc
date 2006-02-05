# $NetBSD: buildlink3.mk,v 1.3 2006/02/05 23:08:33 joerg Exp $

BUILDLINK_DEPTH:=               ${BUILDLINK_DEPTH}+
PHP_PDO_BUILDLINK3_MK:=    ${PHP_PDO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=     php-pdo
.endif

BUILDLINK_PACKAGES:=    ${BUILDLINK_PACKAGES:Nphp-pdo}
BUILDLINK_PACKAGES+=    php-pdo

.if !empty(PHP_PDO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.php-pdo+=        php-pdo-5.*
BUILDLINK_RECOMMENDED.php-pdo?=      php-pdo>=5.1.1.1.0.2nb1
BUILDLINK_PKGSRCDIR.php-pdo?=      ../../databases/php-pdo
BUILDLINK_INCDIRS.php-pdo?=        include/php/ext/pdo
.endif  # PHP_PDO_BUILDLINK3_MK

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
