# $NetBSD: Makefile,v 1.25 2012/09/07 19:16:17 adam Exp $

VERSION=	1.2.1
PKGREVISION=	20
DISTNAME=	pidgin-latex-${VERSION}
EXTRACT_SUFX=	.tar.bz2
CATEGORIES=	chat print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pidgin-latex/}
WRKSRC=		${WRKDIR}/pidgin-latex

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/pidgin-latex/
COMMENT=	Plugin for pidgin to render LaTeX as images

DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	lib/pidgin share/doc/pidgin-latex

do-install:
	${INSTALL_LIB} ${WRKSRC}/LaTeX.so ${DESTDIR}${PREFIX}/lib/pidgin/LaTeX.so

	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pidgin-latex/

DEPENDS+= ImageMagick-[0-9]*:../../graphics/ImageMagick

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-Wl,--export-dynamic
.endif

.include "../../chat/pidgin/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
