# $NetBSD: Makefile,v 1.31 1998/11/02 01:02:12 tron Exp $
#

DISTNAME=	ImageMagick-4.1.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.wizards.dupont.com/cristy/ImageMagick.html

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	mpeg2codec-1.2:../../graphics/mpeg2codec
DEPENDS+=	png-1.0.2:../../graphics/png
DEPENDS+=	tiff-3.4:../../graphics/tiff

CONFLICTS=	ImageMagick-4.0 ImageMagick-4.0.1 ImageMagick-4.0.3 \
		ImageMagick-4.0.5 ImageMagick-4.0.6 ImageMagick-4.0.7 \
		ImageMagick-4.0.8 ImageMagick-4.1.1 ImageMagick-4.1.2

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
