# $NetBSD: Makefile,v 1.4 2020/11/05 09:08:04 ryoon Exp $

DISTNAME=	rpcemu-0.9.3
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://www.marutan.net/rpcemu/cgi/download.php?sFName=${PKGVERSION_NOREV}/

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://www.marutan.net/rpcemu/
COMMENT=	Emulator of classic Acorn computer systems
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	patch
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

INSTALLATION_DIRS+=	bin

post-patch:
	${RUN} cd ${WRKSRC}/src && \
		${PATCH} -p1 <${FILESDIR}/rpcemu-0.9.3-mac-patch-v1.patch
	${RUN} ${MKDIR} ${WRKSRC}/src/macosx
	${RUN} cp ${FILESDIR}/Info.plist ${WRKSRC}/src/macosx/Info.plist

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake src/qt5/rpcemu.pro

do-install:
	${INSTALL} -m 0755 ${WRKSRC}/rpcemu-interpreter \
		${DESTDIR}${PREFIX}/bin/rpcemu-interpreter

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
