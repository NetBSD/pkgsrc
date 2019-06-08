# $NetBSD: Makefile,v 1.39 2019/06/08 10:40:58 rillig Exp $

DISTNAME=	texstudio-2.12.14
PKGREVISION=	5
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=texstudio-org/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://texstudio.sourceforge.net/
COMMENT=	Integrated writing environment for creating LaTeX documents
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++ c
USE_LIBTOOL=	yes

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
_CRASH_HANDLER=	NO_CRASH_HANDLER=yes
.else
_CRASH_HANDLER=
.endif

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake PREFIX=${PREFIX} texstudio.pro DESKTOPDIR=${PREFIX}/share/applications NO_APPDATA=yes ${_CRASH_HANDLER}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
