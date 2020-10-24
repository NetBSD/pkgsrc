# $NetBSD: Makefile,v 1.1 2020/10/24 16:33:34 js Exp $

DISTNAME=	rpcemu-0.9.3
CATEGORIES=	emulators
MASTER_SITES=	http://www.marutan.net/rpcemu/cgi/download.php?sFName=${PKGVERSION_NOREV}/

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://www.marutan.net/rpcemu/
COMMENT=	Emulator of classic Acorn computer systems
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

INSTALLATION_DIRS+=	bin

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake src/qt5/rpcemu.pro

do-install:
	${INSTALL} -m 0755 ${WRKSRC}/rpcemu-interpreter \
		${DESTDIR}${PREFIX}/bin/rpcemu-interpreter

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
