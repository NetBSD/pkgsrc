# $NetBSD: Makefile,v 1.55 2020/06/02 08:23:19 adam Exp $

VERSION=	1.2.1
PKGREVISION=	46
DISTNAME=	pidgin-latex-${VERSION}
EXTRACT_SUFX=	.tar.bz2
CATEGORIES=	chat print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pidgin-latex/}
WRKSRC=		${WRKDIR}/pidgin-latex

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/pidgin-latex/
COMMENT=	Plugin for pidgin to render LaTeX as images

DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS=	lib/pidgin share/doc/pidgin-latex

do-install:
	${INSTALL_LIB} ${WRKSRC}/LaTeX.so ${DESTDIR}${PREFIX}/lib/pidgin/LaTeX.so

	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pidgin-latex/

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

.include "../../chat/pidgin/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
