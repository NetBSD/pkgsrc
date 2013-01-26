# $NetBSD: Makefile,v 1.39 2013/01/26 21:37:54 adam Exp $

DISTNAME=	lcms-1.19
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lcms/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.littlecms.com/
COMMENT=	Little Color Management System -- a color management library
# This is very MIT-like, but perhaps not the exact text.
#LICENSE=	lcms-license

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check

# lcms does not need zlib, but will look for it and link it to tifficc
# if present.  Therefore, we don't enjoin lcms from finding zlib, but
# don't include it via bl3.

PKGCONFIG_OVERRIDE=	lcms.pc.in

INSTALLATION_DIRS+=	share/doc/lcms

post-install:
.for _f_ in LCMSAPI.TXT TUTORIAL.TXT
	${INSTALL_DATA} ${WRKSRC}/doc/${_f_} ${DESTDIR}${PREFIX}/share/doc/lcms/${_f_}
.endfor

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
