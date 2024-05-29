# $NetBSD: Makefile,v 1.75 2024/05/29 16:31:31 adam Exp $

DISTNAME=	pidgin-latex-1.2.1
PKGREVISION=	65
CATEGORIES=	chat print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pidgin-latex/}
EXTRACT_SUFX=	.tar.bz2
WRKSRC=		${WRKDIR}/pidgin-latex

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/pidgin-latex/
COMMENT=	Plugin for pidgin to render LaTeX as images

DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--export-dynamic

INSTALLATION_DIRS=	lib/pidgin share/doc/pidgin-latex

do-install:
	${INSTALL_LIB} ${WRKSRC}/LaTeX.so ${DESTDIR}${PREFIX}/lib/pidgin/LaTeX.so
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pidgin-latex

.include "../../chat/pidgin/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
