# $NetBSD: Makefile,v 1.3 2013/12/29 13:27:56 wiz Exp $

CATEGORIES=	graphics
MASTER_SITES=	http://www.corel.com/akdlm/6763/downloads/AfterShotPro/1/PF/
EXTRACT_SUFX=	.deb

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.corel.com/corel/product/index.jsp?pid=prod4670071
COMMENT=	Photo management software
LICENSE=	corel-license

RESTRICTED=	Redistribution not permitted
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=  ${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=  ${RESTRICTED}

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
USE_TOOLS+=	pax tar

EMUL_PLATFORMS=		linux-i386 # linux-x86_64
EMUL_MODULES.linux=	drm fontconfig freetype2 glx gtk2 png x11

INSTALLATION_DIRS=	bin libdata share/applications share/pixmaps

REPLACE_SH=		usr/bin/AfterShotPro

SUBST_CLASSES+=		path
SUBST_SED.path+=	-e "s,/opt/AfterShotPro,${PREFIX}/libdata/AfterShotPro,"
SUBST_SED.path+=	-e "s,{LD_LIBRARY_PATH},{LD_LIBRARY_PATH}:${PREFIX}/emul/linux32/lib,"
SUBST_FILES.path+=	usr/bin/AfterShotPro
SUBST_MESSAGE.path=	Fixing path for pkgsrc.
SUBST_STAGE.path=	post-build

.include "../../mk/bsd.prefs.mk"

DIST_SUBDIR=	AfterShotPro-1.1.0.30

.if ${EMUL_PLATFORM} == "linux-i386"
DISTNAME=	AfterShotPro_i386
PKGNAME=	${DISTNAME:S/_i386/-1.1.0.30/}
# same data.tar.gz, just different control.tar.gz
#.elif ${EMUL_PLATFORM} == "linux-x86_64"
#DISTNAME=	AfterShotPro_amd64
#PKGNAME=	${DISTNAME:S/_amd64/-1.1.0.30/}
.else
BROKEN=		Not supported for this emulation
.endif

do-extract: ${WRKDIR}
	${RUN} cd ${WRKDIR} && ${AR} x ${_DISTDIR:Q}/${DISTNAME}${EXTRACT_SUFX} data.tar.gz
	cd ${WRKSRC} && ${TAR} -xzpf data.tar.gz
	chmod go-w ${WRKSRC}

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/usr/bin/AfterShotPro ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/usr/share/applications/AfterShotPro.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/usr/share/pixmaps/AfterShotPro.png ${DESTDIR}${PREFIX}/share/pixmaps
	cd ${WRKSRC}/opt && pax -pe -rw * ${DESTDIR}${PREFIX}/libdata
	cd ${DESTDIR}${PREFIX} && chmod -R go-w .

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
