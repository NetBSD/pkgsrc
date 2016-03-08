# $NetBSD: Makefile,v 1.3 2016/03/08 20:21:50 imil Exp $

DISTNAME=	facette-0.4.0dev
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=facette/}
GITHUB_PROJECT=	facette
GITHUB_TAG=	d77e77680d52d232305d0f12af6e3e1c857903cb

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://facette.io/
COMMENT=	Time series data visualization and graphing
LICENSE=	modified-bsd

EXTRACT_USING=	bsdtar

USE_TOOLS+=	bsdtar gmake gsed pax pkg-config
BUILD_DEPENDS+=	go-[0-9]*:../../lang/go
BUILD_DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-build
SUBST_FILES.paths=	Makefile
SUBST_SED.paths=	-e 's,/usr/local,${PREFIX}/,g'

DOCDIR=			${PREFIX}/share/doc/facette
EGDIR=			${PREFIX}/share/examples/facette
DATADIR=		${PREFIX}/share/facette
INSTALLATION_DIRS+=	bin ${EGDIR} ${DOCDIR}
INSTALLATION_DIRS+=	${DATADIR}/template ${DATADIR}/static

CGO_LDFLAGS=		-L${PREFIX}/lib ${COMPILER_RPATH_FLAG},${PREFIX}/lib

do-build:
	cd ${WRKSRC} && CGO_LDFLAGS="${CGO_LDFLAGS}" ${GMAKE} build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/*/bin/facette	\
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/build/*/bin/facettectl	\
		${DESTDIR}${PREFIX}/bin/
	cd ${WRKSRC}/docs/man && ${PAX} -rw * ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/docs/examples && ${PAX} -rw * ${DESTDIR}${EGDIR}
	cd ${WRKSRC}/build/*/template &&	\
		${PAX} -rw * ${DESTDIR}${DATADIR}/template
	cd ${WRKSRC}/build/*/static &&		\
		${PAX} -rw * ${DESTDIR}${DATADIR}/static


.include "../../databases/rrdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
