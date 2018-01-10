# $NetBSD: Makefile,v 1.17 2018/01/10 22:31:08 wiz Exp $

DISTNAME=	texstudio-2.12.6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=texstudio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://texstudio.sourceforge.net/
COMMENT=	Integrated writing environment for creating LaTeX documents
LICENSE=	gnu-gpl-v2

BROKEN=		Needs to be converted to qt5

WRKSRC=		${WRKDIR}/${DISTNAME:S/-//}

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++ c
USE_LIBTOOL=	yes

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
_CRASH_HANDLER=NO_CRASH_HANDLER=yes
.else
_CRASH_HANDLER=
.endif

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake PREFIX=${PREFIX} texstudio.pro DESKTOPDIR=${PREFIX}/share/applications NO_APPDATA=yes ${_CRASH_HANDLER}

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
#.include "../../print/poppler-qt4/buildlink3.mk"
#.include "../../print/poppler-includes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
