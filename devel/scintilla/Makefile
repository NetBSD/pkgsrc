# $NetBSD: Makefile,v 1.14 2013/02/16 11:18:47 wiz Exp $
#

DISTNAME=	scintilla229
PKGNAME=	scintilla-2.29
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scintilla/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scintilla.sourceforge.net/
COMMENT=	Source code editing component
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/scintilla
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
BUILD_DIRS=	gtk
MAKE_FILE=	makefile

INSTALLATION_DIRS= include lib
do-install:
	${INSTALL_DATA} ${WRKSRC}/include/Scintilla.h \
		${WRKSRC}/include/ScintillaWidget.h \
		${WRKSRC}/include/SciLexer.h \
		${DESTDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/bin/scintilla.a ${DESTDIR}${PREFIX}/lib

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
