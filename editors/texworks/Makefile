# $NetBSD: Makefile,v 1.27 2015/01/08 10:20:34 wiz Exp $

DISTNAME=	texworks-0.4.5-r1281
PKGNAME=	texworks-0.4.5
PKGREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	http://texworks.googlecode.com/files/

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.tug.org/texworks/
COMMENT=	Simple TeX front-end program
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gmake
MAKE_ENV+=	INSTALL_ROOT=${DESTDIR}

DEPENDS+=	poppler-data>=0.4.5:../../print/poppler-data

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

SUBST_CLASSES+=man
SUBST_STAGE.man=post-configure
SUBST_FILES.man=Makefile
SUBST_SED.man=-e s!/share/man/man1!/man/man1!g

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

do-configure:
	cd ${WRKSRC}; env QTDIR=${QTDIR} qmake INSTALL_PREFIX=${PREFIX} TW_DICPATH=${BUILDLINK_PREFIX.hunspell}/share/hunspell

BUILDLINK_DEPMETHOD.qt4-tools=	full

.include "../../devel/zlib/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
