# $NetBSD: Makefile,v 1.74 2022/07/02 16:53:14 ryoon Exp $

DISTNAME=	texstudio-2.12.22
PKGREVISION=	27
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=texstudio-org/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://texstudio.org/
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
	${QTDIR}/bin/qmake PREFIX=${PREFIX} texstudio.pro USE_SYSTEM_HUNSPELL=1 DESKTOPDIR=${PREFIX}/share/applications NO_APPDATA=yes ${_CRASH_HANDLER}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
