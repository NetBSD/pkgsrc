# $NetBSD: Makefile,v 1.7 2016/03/04 16:55:45 fhajny Exp $

DISTNAME=	barman-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pgbarman/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.pgbarman.org/
COMMENT=	Backup and Recovery Manager for PostgreSQL
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-argcomplete-[0-9]*:../../devel/py-argcomplete
DEPENDS+=	${PYPKGPREFIX}-argh>=0.21.2:../../devel/py-argh
DEPENDS+=	${PYPKGPREFIX}-psycopg2-[0-9]*:../../databases/py-psycopg2
DEPENDS+=	rsync-[0-9]*:../../net/rsync

PYTHON_VERSIONED_DEPENDENCIES=	dateutil

USE_LANGUAGES=	# none

CONF_FILES+=		share/examples/barman/barman.conf \
			${PKG_SYSCONFDIR}/barman.conf
INSTALLATION_DIRS+=	share/examples/barman

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		VARBASE

BARMAN_DIR?=		${VARBASE}/lib/barman
BARMAN_LOG_DIR?=	${VARBASE}/log/barman
BARMAN_USER=		barman
BARMAN_GROUP=		${BARMAN_USER}

PKG_GROUPS+=		${BARMAN_GROUP}
PKG_USERS+=		${BARMAN_USER}:${BARMAN_GROUP}
PKG_GECOS.barman=	PG Barman user
PKG_HOME.barman=	${BARMAN_DIR}

OWN_DIRS_PERMS+=	${BARMAN_DIR} ${BARMAN_USER} ${BARMAN_GROUP} 0700
OWN_DIRS_PERMS+=	${BARMAN_LOG_DIR} ${BARMAN_USER} ${BARMAN_GROUP} 0755

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	barman/config.py doc/barman.conf setup.py
SUBST_MESSAGE.path=	Fixing paths
SUBST_SED.path=		-e 's,/etc/,${PKG_SYSCONFDIR}/,g'
SUBST_SED.path+=	-e 's,/var/lib/barman,${BARMAN_DIR},g'
SUBST_SED.path+=	-e 's,/var/log/barman,${BARMAN_LOG_DIR},g'
SUBST_SED.path+=	-e 's,share/man,${PKGMANDIR},g'

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/barman.conf \
		${DESTDIR}${PREFIX}/share/examples/barman/barman.conf

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
