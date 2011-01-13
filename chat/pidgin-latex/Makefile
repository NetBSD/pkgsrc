# $NetBSD: Makefile,v 1.11 2011/01/13 13:37:14 wiz Exp $

VERSION=	1.2.1
PKGREVISION=	8
DISTNAME=	pidgin-latex-${VERSION}
EXTRACT_SUFX=	.tar.bz2
CATEGORIES=	chat print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pidgin-latex/}
WRKSRC=		${WRKDIR}/pidgin-latex

MAINTAINER=	smb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/pidgin-latex/
COMMENT=	Plugin for pidgin to render LaTeX as images

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	lib/pidgin share/doc/pidgin-latex

do-install:
	${INSTALL_LIB} ${WRKSRC}/LaTeX.so ${DESTDIR}${PREFIX}/lib/pidgin/LaTeX.so

	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pidgin-latex/

DEPENDS+= ImageMagick-[0-9]*:../../graphics/ImageMagick

.include "../../chat/pidgin/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
