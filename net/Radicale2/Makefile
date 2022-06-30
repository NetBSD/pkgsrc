# $NetBSD: Makefile,v 1.13 2022/06/30 11:18:39 nia Exp $

DISTNAME=	Radicale-2.1.5
PKGREVISION=	4
CATEGORIES=	net time www
MASTER_SITES=	${MASTER_SITE_PYPI:=R/Radicale/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://radicale.org/
COMMENT=	CalDAV (calendar) and CardDAV (contact) server
LICENSE=	gnu-gpl-v3

EGDIR=			share/examples/radicale

RADICALE_USER?=			www
RADICALE_GROUP?=		www
PKG_GROUPS=			${RADICALE_GROUP}
PKG_USERS=			${RADICALE_USER}:${RADICALE_GROUP}
PYTHON_VERSIONS_INCOMPATIBLE=	27

INSTALLATION_DIRS=	${EGDIR}
OWN_DIRS=		${PKG_SYSCONFDIR}/radicale
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/radicale/config
RCD_SCRIPTS=		radicale
FILES_SUBST+=		RADICALE_USER=${RADICALE_USER}
FILES_SUBST+=		RADICALE_GROUP=${RADICALE_GROUP}
FILES_SUBST+=		PYTHONBIN=${PYTHONBIN}

SUBST_CLASSES+=		config
SUBST_SED.config+=	-e 's,/etc,${PKG_SYSCONFDIR},g'
SUBST_SED.config+=	-e 's,/var/lib,${PREFIX}/share,g'
SUBST_FILES.config+=	radicale/config.py config logging
SUBST_STAGE.config=	pre-configure
SUBST_MESSAGE.config=	Fixing path to configuration file.

SUBST_CLASSES+=		server
SUBST_SED.server+=	-e 's,\#daemon = False,daemon = True,'
SUBST_SED.server+=	-e 's,\#filesystem_folder,filesystem_folder,'
SUBST_FILES.server+=	config
SUBST_STAGE.server=	pre-configure
SUBST_MESSAGE.server=	Configure as a daemon by default, and override default collection location

# no options currently available
# .include "options.mk"

DEPENDS+=		${PYPKGPREFIX}-vobject-[0-9]*:../../textproc/py-vobject

# for md5 htpasswd_encryption method
DEPENDS+=		${PYPKGPREFIX}-passlib-[0-9]*:../../security/py-passlib


post-install:
	${INSTALL_DATA} ${WRKSRC}/config ${DESTDIR}${PREFIX}/${EGDIR}/config

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
