# $NetBSD: Makefile,v 1.35 1999/03/03 18:45:08 tron Exp $
#

DISTNAME=	ImageMagick-4.2.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.wizards.dupont.com/cristy/ImageMagick.html

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	mpeg2codec-1.2:../../graphics/mpeg2codec
DEPENDS+=	png-1.0.2:../../graphics/png
DEPENDS+=	tiff-3.4:../../graphics/tiff

pre-configure:
.if exists(/usr/lib/libbz2.a)
		@echo >${WRKSRC}/bzlib.tmpl "#define HasBZLIB"
.else
		@echo >${WRKSRC}/bzlib.tmpl
.endif
		@cd ${WRKSRC} && ./configure --prefix=${X11BASE}

MIRROR_DISTFILE= no
USE_IMAKE=	yes
XMKMF=		${MAKE_ENV} xmkmf -a
MAKE_ENV+=	LOCALBASE=${LOCALBASE} PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
