# $NetBSD: Makefile,v 1.16 2011/11/01 06:00:47 sbd Exp $

VERSION=	1.2.1
PKGREVISION=	12
DISTNAME=	pidgin-latex-${VERSION}
EXTRACT_SUFX=	.tar.bz2
CATEGORIES=	chat print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pidgin-latex/}
WRKSRC=		${WRKDIR}/pidgin-latex

MAINTAINER=	pkgsrc-users@NetBSD.org
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
