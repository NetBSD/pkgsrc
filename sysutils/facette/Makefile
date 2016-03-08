# $NetBSD: Makefile,v 1.1 2016/03/08 16:52:44 imil Exp $

DISTNAME=	facette-0.4.0dev
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

MAKE_ENV+=		CGO_LDFLAGS="-L${PREFIX}/lib -Wl,-rpath,${PREFIX}/lib"

DOCDIR=			${PREFIX}/share/doc/facette
EGDIR=			${PREFIX}/share/examples/facette
DATADIR=		${PREFIX}/share/facette
INSTALLATION_DIRS+=	bin ${EGDIR} ${DOCDIR} ${DATADIR}/static

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/*/bin/facette	\
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/build/*/bin/facettectl	\
		${DESTDIR}${PREFIX}/bin/
	cd ${WRKSRC}/docs/man && ${PAX} -rw * ${DESTDIR}${DOCDIR}
	cd ${WRKSRC}/docs/examples && ${PAX} -rw * ${DESTDIR}${EGDIR}
	cd ${WRKSRC}/build/*/template && ${PAX} -rw * ${DESTDIR}${DATADIR}
	cd ${WRKSRC}/build/*/static && ${PAX} -rw * ${DESTDIR}${DATADIR}/static


.include "../../databases/rrdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
