# $NetBSD: Makefile,v 1.20 2018/11/14 22:22:23 kleink Exp $

DISTNAME=	facette-0.4.0dev
PKGREVISION=	18
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=facette/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://facette.io/
COMMENT=	Time series data visualization and graphing
LICENSE=	modified-bsd

GITHUB_PROJECT=	facette
GITHUB_TAG=	d77e77680d52d232305d0f12af6e3e1c857903cb

EXTRACT_USING=	bsdtar

BROKEN=		Tries to install uglify-js during build.

.include "../../lang/go/version.mk"

USE_TOOLS+=	bsdtar gmake gsed pax pkg-config
BUILD_DEPENDS+=	${GO_PACKAGE_DEP}
BUILD_DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

BUILD_DEFS+=		VARBASE

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing prefix.
SUBST_STAGE.prefix=	pre-build
SUBST_FILES.prefix=	Makefile docs/examples/facette.json
SUBST_SED.prefix=	-e 's,/usr/local,${PREFIX},g'

SUBST_CLASSES+=		conf
SUBST_MESSAGE.conf=	Fixing configuration path.
SUBST_STAGE.conf=	pre-build
SUBST_FILES.conf=	cmd/facette/facette.go	\
			cmd/facettectl/facettectl.go	\
			docs/examples/facette.json	\
			docs/man/facette.1.md		\
			docs/man/facettectl.8.md	\
			pkg/config/config.go
SUBST_SED.conf=		-e 's,/etc,${PKG_SYSCONFDIR},g'

SUBST_CLASSES+=		rrd
SUBST_MESSAGE.rrd=	Fixing collectd rrd path.
SUBST_STAGE.rrd=	pre-build
SUBST_FILES.rrd=	docs/examples/providers/collectd.json
SUBST_SED.rrd=		-e 's,/var/lib,${VARBASE}/db,g'

CHECK_PORTABILITY_SKIP=	vendor/src/github.com/influxdb/influxdb/configure

.include "../../mk/bsd.prefs.mk"

FACETTE_USER?=		facette
FACETTE_GROUP?=		facette

RCD_SCRIPTS+=		facette
RCD_SCRIPT_SRC.facette=	${FILESDIR}/facette.sh

FACETTE_DOCDIR=		${PREFIX}/share/doc/facette
FACETTE_HTDOCS=		${PREFIX}/share/facette
FACETTE_DATADIR=	${VARBASE}/lib/facette
FACETTE_LOGDIR=		${VARBASE}/log/facette
EGDIR=			${PREFIX}/share/examples/facette

INSTALLATION_DIRS+=	bin ${EGDIR} ${FACETTE_DOCDIR}
INSTALLATION_DIRS+=	${FACETTE_HTDOCS}/template ${FACETTE_HTDOCS}/static

OWN_DIRS+=		${PKG_SYSCONFDIR}/facette
OWN_DIRS+=		${PKG_SYSCONFDIR}/facette/providers
OWN_DIRS+=		${VARBASE}/run/facette
OWN_DIRS+=		${FACETTE_DATADIR} ${FACETTE_LOGDIR}

OWN_DIRS_PERMS+=	${VARBASE}/run/facette			\
				${FACETTE_USER} ${FACETTE_GROUP} 0755
OWN_DIRS_PERMS+=	${FACETTE_DATADIR}			\
				${FACETTE_USER} ${FACETTE_GROUP} 0755
OWN_DIRS_PERMS+=	${FACETTE_LOGDIR}			\
				${FACETTE_USER} ${FACETTE_GROUP} 0755

PKG_GROUPS+=			${FACETTE_GROUP}
PKG_USERS+=			${FACETTE_USER}:${FACETTE_GROUP}
PKG_GECOS.${FACETTE_USER}=	Facette daemon user
PKG_HOME.${FACETTE_USER}=	${FACETTE_DATADIR}

FILES_SUBST+=		FACETTE_USER=${FACETTE_USER}
FILES_SUBST+=		FACETTE_GROUP=${FACETTE_GROUP}
FILES_SUBST+=		FACETTE_LOGDIR=${FACETTE_LOGDIR}

CONF_FILES+=		${EGDIR}/facette.json			\
			${PKG_SYSCONFDIR}/facette/facette.json
CONF_FILES+=		${EGDIR}/providers/collectd.json	\
			${PKG_SYSCONFDIR}/facette/providers/collectd.json

CGO_LDFLAGS=		-L${PREFIX}/lib ${COMPILER_RPATH_FLAG},${PREFIX}/lib

do-build:
	cd ${WRKSRC} && CGO_LDFLAGS=${CGO_LDFLAGS:Q} ${GMAKE} build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/*/bin/facette	\
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/build/*/bin/facettectl	\
		${DESTDIR}${PREFIX}/bin/
	cd ${WRKSRC}/docs/man && ${PAX} -rw * ${DESTDIR}${FACETTE_DOCDIR}
	cd ${WRKSRC}/docs/examples && ${PAX} -rw * ${DESTDIR}${EGDIR}
	cd ${WRKSRC}/build/*/template &&	\
		${PAX} -rw * ${DESTDIR}${FACETTE_HTDOCS}/template
	cd ${WRKSRC}/build/*/static &&		\
		${PAX} -rw * ${DESTDIR}${FACETTE_HTDOCS}/static


.include "../../databases/rrdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
