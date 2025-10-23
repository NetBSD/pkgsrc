# $NetBSD: Makefile,v 1.1 2025/10/23 01:11:01 khorben Exp $

PLUGIN=		html5_notifier
DISTNAME=	${PLUGIN}-0.6.4
CATEGORIES=	mail
PKGNAME=	${PHP_PKG_PREFIX}-roundcube-plugin-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=stremlau/}
GITHUB_PROJECT=	${PLUGIN}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	HTML5 Notifier plugin for roundcube
LICENSE=	0-clause-bsd

DEPENDS+=	${PHP_PKG_PREFIX}-roundcube>=1.6.11:../../mail/roundcube
USE_TOOLS+=	pax
NO_BUILD=	yes

RCDIR=		share/roundcube
EGDIR=		share/examples/roundcube

PKG_SYSCONFSUBDIR=	roundcube

PKG_GROUPS_VARS+=	WWW_GROUP
PKG_USERS_VARS=		WWW_USER

INSTALLATION_DIRS+=	${RCDIR}/plugins/${PLUGIN}
INSTALLATION_DIRS+=	${EGDIR}/plugins/${PLUGIN}
CONF_FILES_PERMS+=	${EGDIR}/plugins/${PLUGIN}/config.inc.php \
			${PKG_SYSCONFDIR}/${PLUGIN}.inc.php \
			${WWW_USER} ${WWW_GROUP} 0640

do-install:
	${INSTALL_DATA} ${WRKSRC}/config/config.inc.php.dist \
		${DESTDIR}${PREFIX}/${EGDIR}/plugins/${PLUGIN}/config.inc.php
	cd ${WRKSRC} && ${FIND} . -type f \! -name "*.orig" \! -name .gitignore -print | \
		${PAX} -rw ${DESTDIR}${PREFIX}/${RCDIR}/plugins/${PLUGIN}

.include "../../mail/roundcube/options.mk"
.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
