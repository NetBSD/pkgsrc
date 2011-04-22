# $NetBSD: Makefile,v 1.13 2011/04/22 13:44:31 obache Exp $
#

DISTNAME=	diffpdf-1.1.5
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.qtrac.eu/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qtrac.eu/diffpdf.html
COMMENT=	PDF comparision tool
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++
INSTALLATION_DIRS+= bin ${PKGMANDIR}/man1

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/diffpdf ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/diffpdf.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../print/poppler-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
