# $NetBSD$
#
# Support for dependency several php packages which was contained
# in base PHP distributions.
#
# PHP_REQUIRE_MODULE
#	list of key words which speicifies conditionally depending
#	php packages.
#
#	Possible:	apcu imap json mcrypt opcache
#	Default:	(empty)
#
.if !defined(PHP_COMPAT_MK)
PHP_COMPAT_MK:=	# empty

.include "../../lang/php/phpversion.mk"

.if ${PHP_REQUIRE_MODULE:Mapcu}
. if ${PHP_VER} < 70
DEPENDS+=	${PHP_PKG_PREFIX}-apcu<5:../../www/php-apcu4
. else
DEPENDS+=	${PHP_PKG_PREFIX}-apcu>=5:../../www/php-apcu
. include "../../www/php-apcu/buildlink3.mk"
. endif
.endif # apcu

.if ${PHP_REQUIRE_MODULE:Mimap}
. if ${PHP_VER} < 84
DEPENDS+=	${PHP_PKG_PREFIX}-imap>=${PHP_BASE_VERS}:../../mail/php-imap
. else
DEPENDS+=	${PHP_PKG_PREFIX}-imap>=1.0.3:../../mail/php-pecl-imap
. endif
.endif # imap

.if ${PHP_REQUIRE_MODULE:Mjson}
. if ${PHP_VER} < 80
DEPENDS+=	${PHP_PKG_PREFIX}-json>=${PHP_BASE_VERS}:../../textproc/php-json
. include "../../textproc/php-json/buildlink3.mk"
. endif
.endif # json

.if ${PHP_REQUIRE_MODULE:Mmcrypt}
. if ${PHP_VER} < 71
DEPENDS+=	${PHP_PKG_PREFIX}-mcrypt>=${PHP_BASE_VERS}:../../security/php-mcrypt
.  else
DEPENDS+=	${PHP_PKG_PREFIX}-pecl-mcrypt>=1.0.1:../../security/php-pecl-mcrypt
.  endif
.endif # mcrypt

.if ${PHP_REQUIRE_MODULE:Mopcache}
. if ${PHP_VER} < 85
DEPENDS+=	${PHP_PKG_PREFIX}-opcache>=${PHP_BASE_VERS}:../../devel/php-opcache
. endif
.endif # opcache

.endif	# PHP_COMPAT_MK
