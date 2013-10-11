# $NetBSD: Makefile,v 1.9 2013/10/11 09:59:54 wiz Exp $

DISTNAME=	Radicale-0.8
PKGREVISION=	1
CATEGORIES=	net time www
MASTER_SITES=	http://pypi.python.org/packages/source/R/Radicale/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://radicale.org/
COMMENT=	CalDAV (calendar) and CardDAV (contact) server
LICENSE=	gnu-gpl-v3

PYDISTUTILSPKG=		yes
EGDIR=			share/examples/radicale

PYTHON_VERSIONS_INCLUDE_3X=	yes
INSTALLATION_DIRS=	${EGDIR}
OWN_DIRS=		${PKG_SYSCONFDIR}/radicale
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/radicale/config

SUBST_CLASSES+=		config
SUBST_SED.config+=	-e 's,/etc/radicale/config,${PKG_SYSCONFDIR}/radicale/config,'
SUBST_FILES.config+=	radicale/config.py
SUBST_STAGE.config=	pre-configure
SUBST_MESSAGE.config=	Fixing path to configuration file.

post-build:
	${SED} -e "s#/etc#${PKG_SYSCONFDIR}#" -e "s#apache2/#httpd/#" \
	  ${WRKSRC}/config >${WRKSRC}/config.pkgsrc

post-install:
	${INSTALL_DATA} ${WRKSRC}/config.pkgsrc \
	  ${DESTDIR}${PREFIX}/${EGDIR}/config

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
