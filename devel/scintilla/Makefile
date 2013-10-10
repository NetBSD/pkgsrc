# $NetBSD: Makefile,v 1.20 2013/10/10 14:42:05 ryoon Exp $
#

DISTNAME=	scintilla325
PKGNAME=	scintilla-3.2.5
PKGREVISION=	5
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

INSTALLATION_DIRS= include/scintilla lib
do-install:
	${INSTALL_DATA} ${WRKSRC}/include/Scintilla.h \
		${WRKSRC}/include/ScintillaWidget.h \
		${WRKSRC}/include/SciLexer.h \
		${WRKSRC}/include/ILexer.h \
		${DESTDIR}${PREFIX}/include/scintilla
	${INSTALL_LIB} ${WRKSRC}/bin/scintilla.a ${DESTDIR}${PREFIX}/lib

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
