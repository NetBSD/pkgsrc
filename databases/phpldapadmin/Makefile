# $NetBSD: Makefile,v 1.20 2006/05/18 22:22:37 adrianp Exp $

DISTNAME=	phpldapadmin-${VERSION}
CATEGORIES=	databases www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phpldapadmin/}

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://phpldapadmin.sourceforge.net/
COMMENT=	Set of PHP-scripts to administer an LDAP directory over the WWW

.include "../../lang/php/phpversion.mk"

DEPENDS+=	php-ldap>=4.1.2:../../databases/php-ldap
DEPENDS+=	php-gettext>=4.1.2:../../devel/php-gettext
.if ${PKG_PHP_VERSION} == "4"
DEPENDS+=	php-domxml>=4.1.2:../../textproc/php4-domxml
.elif ${PKG_PHP_VERSION} == "5"
DEPENDS+=	php-dom-[0-9]*:../../textproc/php5-dom
.endif

VERSION=	0.9.8.3
NO_BUILD=	YES
BUILD_DEFS+=	WWW_USER

CONF_FILES=	${PREFIX}/share/examples/phpldapadmin/config.php.example \
		${PREFIX}/share/phpldapadmin/config/config.php
CONF_FILES+=	${PREFIX}/share/examples/phpldapadmin/phpldapadmin.conf \
		${PKG_SYSCONFDIR}/phpldapadmin.conf
SPECIAL_PERMS=	${PREFIX}/share/phpldapadmin/config/config.php \
		${WWW_USER} ${ROOT_GROUP} 0600
PAX_DIRS=	config doc htdocs lib locale templates tools

# NOTE: If you're running apache under an account other than www or
# are running a different web server under a specific user account
# you should set WWW_USER in your mk.conf.
#
.if !defined(WWW_USER)
WWW_USER=	${APACHE_USER}
.endif

do-configure:
	${SED} -e "s|@LDAPADMINDIR@|${PREFIX}/share/phpldapadmin/htdocs|g" \
		${FILESDIR}/phpldapadmin.conf > ${WRKDIR}/phpldapadmin.conf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/phpldapadmin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/phpldapadmin
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpldapadmin

	${INSTALL_DATA} ${WRKSRC}/config/config.php.example \
		${PREFIX}/share/examples/phpldapadmin
	${INSTALL_DATA} ${WRKDIR}/phpldapadmin.conf \
		${PREFIX}/share/examples/phpldapadmin

	${RM} ${WRKSRC}/.cvsignore
	${RM} ${WRKSRC}/config/.cvsignore
	${RM} ${WRKSRC}/config/config.php.example

	${INSTALL_DATA} ${WRKSRC}/index.php ${PREFIX}/share/phpldapadmin

.for i in ${PAX_DIRS}
		@cd ${WRKSRC}/${i:Q} && ${PAX} \
			-rwppm . ${PREFIX}/share/phpldapadmin/${i:Q}
.endfor

	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/phpldapadmin
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/phpldapadmin
	${INSTALL_DATA} ${WRKSRC}/VERSION ${PREFIX}/share/phpldapadmin

	${FIND} ${PREFIX}/share/doc/phpldapadmin -type d | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}

.include "../../mk/bsd.pkg.mk"
