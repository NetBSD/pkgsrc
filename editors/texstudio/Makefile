# $NetBSD: Makefile,v 1.1 2016/02/07 22:29:04 markd Exp $

DISTNAME=	texstudio-2.10.8
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=texstudio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://texstudio.sourceforge.net/
COMMENT=	Integrated writing environment for creating LaTeX documents
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME:S/-//}

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++ c
USE_LIBTOOL=	yes

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake PREFIX=${PREFIX} texstudio.pro DESKTOPDIR=${PREFIX}/share/applications NO_APPDATA=yes

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
