# $NetBSD: Makefile,v 1.4 2026/01/07 08:46:24 wiz Exp $

DISTNAME=	Guitar-1.3.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=soramimi/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/soramimi/Guitar/
COMMENT=	Git GUI Client
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	ruby34-[0-9]*:../../lang/ruby34

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	filetype/file/libmagic.pc.in

# fix qt warning
MAKE_ENV+=	LANG=C.UTF-8

BUILD_DIRS=		filetype .
INSTALLATION_DIRS+=	bin

do-configure:
	cd ${WRKSRC}/filetype && ${QTDIR}/bin/qmake libfile.pro
	cd ${WRKSRC}/filetype && ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/filetype && ${QTDIR}/bin/qmake libfiletype.pro
	cd ${WRKSRC}/filetype && ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/filetype && ${QTDIR}/bin/qmake liboniguruma.pro
	cd ${WRKSRC}/filetype && ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC} && ${QTDIR}/bin/qmake Guitar.pro
	${LN} -s ${PREFIX}/bin/ruby34 ${BUILDLINK_DIR}/bin/ruby

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/_bin/Guitar ${DESTDIR}${PREFIX}/bin

.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
