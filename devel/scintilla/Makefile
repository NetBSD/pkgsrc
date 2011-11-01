# $NetBSD: Makefile,v 1.5 2011/11/01 06:01:04 sbd Exp $
#

DISTNAME=	scintilla225
PKGNAME=	scintilla-2.25
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scintilla/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://scintilla.sourceforge.net/
COMMENT=	Source code editing component
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

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
