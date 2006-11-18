# $NetBSD: Makefile,v 1.25 2006/11/18 21:46:44 ghen Exp $

DISTNAME=	phpldapadmin-${VERSION}
CATEGORIES=	databases www
PKGREVISION=	4
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=phpldapadmin/}

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://phpldapadmin.sourceforge.net/
COMMENT=	Set of PHP-scripts to administer an LDAP directory over the WWW

.include "../../mk/bsd.prefs.mk"
.include "../../lang/php/phpversion.mk"

DEPENDS+=	${PHP_PKG_PREFIX}-ldap>=4.1.2:../../databases/php-ldap
DEPENDS+=	${PHP_PKG_PREFIX}-gettext>=4.1.2:../../devel/php-gettext

VERSION=	0.9.8.3
NO_BUILD=	YES

CONF_FILES_PERMS+=  ${PREFIX}/share/examples/phpldapadmin/config.php.example \
		${PREFIX}/share/phpldapadmin/config/config.php		 \
		${ROOT_USER} ${ROOT_GROUP} 0644
CONF_FILES+=	${PREFIX}/share/examples/phpldapadmin/phpldapadmin.conf \
		${PKG_SYSCONFDIR}/phpldapadmin.conf
PAX_DIRS=	config doc htdocs lib locale templates tools

do-configure:
	${SED} -e "s|@LDAPADMINDIR@|${PREFIX}/share/phpldapadmin/htdocs|g" \
		${FILESDIR}/phpldapadmin.conf > ${WRKDIR}/phpldapadmin.conf

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/phpldapadmin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/phpldapadmin
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpldapadmin
	${INSTALL_DATA_DIR} ${PREFIX}/share/phpldapadmin/config

	${INSTALL_DATA} ${WRKSRC}/config/config.php.example \
		${PREFIX}/share/examples/phpldapadmin/config.php.example
	${INSTALL_DATA} ${WRKDIR}/phpldapadmin.conf \
		${PREFIX}/share/examples/phpldapadmin/phpldapadmin.conf

	${RM} ${WRKSRC}/.cvsignore
	${RM} ${WRKSRC}/config/.cvsignore

	${INSTALL_DATA} ${WRKSRC}/index.php ${PREFIX}/share/phpldapadmin

.for i in ${PAX_DIRS}
	cd ${WRKSRC}/${i:Q} && ${PAX} \
		-rwppm . ${PREFIX}/share/phpldapadmin/${i:Q}
.endfor

	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/phpldapadmin
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/phpldapadmin
	${INSTALL_DATA} ${WRKSRC}/VERSION ${PREFIX}/share/phpldapadmin

	${FIND} ${PREFIX}/share/phpldapadmin -type d | \
		${XARGS} ${CHMOD} ${PKGDIRMODE}

.include "../../mk/bsd.pkg.mk"
