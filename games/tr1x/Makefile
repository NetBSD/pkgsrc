# $NetBSD: Makefile,v 1.1 2024/05/26 10:29:06 nia Exp $

DISTNAME=	TR1X-4.1.2
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=LostArtefacts/}
GITHUB_PROJECT=	TR1X

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/LostArtefacts/TR1X
COMMENT=	Open source re-implementation of Tomb Raider
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config pax

MESON_INSTALL=	no
MESON_ARGS+=	-Dstaticdeps=false

USE_CC_FEATURES+=	c11

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	share/tr1x
INSTALLATION_DIRS+=	libexec

pre-configure:
	${SED}  -e 's,@PREFIX@,${PREFIX},g' \
                < ${FILESDIR}/tr1x.sh.in > \
                ${WRKDIR}/tr1x

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/tr1x \
		${DESTDIR}${PREFIX}/bin/tr1x
	${INSTALL_PROGRAM} ${WRKSRC}/output/TR1X \
		${DESTDIR}${PREFIX}/libexec/tr1x
	${INSTALL_DATA} ${FILESDIR}/tr1x.desktop \
		${DESTDIR}${PREFIX}/share/applications/tr1x.desktop
	${INSTALL_DATA} ${WRKSRC}/tools/installer/Installer/Resources/TR1X.png \
		${DESTDIR}${PREFIX}/share/pixmaps/tr1x.png
	cd ${WRKSRC}/data/ship && ${PAX} -rw -pp . \
		${DESTDIR}${PREFIX}/share/tr1x

.include "../../devel/meson/build.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
