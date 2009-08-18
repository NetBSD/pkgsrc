# $NetBSD: Makefile,v 1.5 2009/08/18 15:23:59 joerg Exp $

PKGNAME=	${DISTNAME:S/-/-qt-console-/}
PKGREVISION=	2
COMMENT=	Qt-based console for Bacula - The Network Backup Solution

PKG_DESTDIR_SUPPORT=	user-destdir

DISTINFO_FILE=		${.CURDIR}/../../sysutils/bacula/distinfo
PATCHDIR=		${.CURDIR}/../../sysutils/bacula/patches

USE_TOOLS+=		gmake pkg-config
CONFIGURE_ARGS+=	--enable-client-only
CONFIGURE_ARGS+=	--enable-bat

BUILD_DIRS=		src/qt-console

INSTALLATION_DIRS=	bin share/examples/bacula

CONF_FILES+=		${EXAMPLESDIR}/bat.conf ${PKG_SYSCONFDIR}/bat.conf

post-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/src/qt-console/bat ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/qt-console/bat.conf ${DESTDIR}${EXAMPLESDIR}

.include "../../sysutils/bacula/Makefile.common"
.include "../../sysutils/bacula/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
