# $NetBSD: Makefile,v 1.15 2005/01/17 12:11:46 adam Exp $
# FreeBSD: ports/graphics/lcms/Makefile,v 1.2 2000/12/19 15:36:26 sobomax Exp

DISTNAME=	lcms-1.14
CATEGORIES=	graphics
MASTER_SITES=	http://www.littlecms.com/ \
		http://www.abaforum.es/martim/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.littlecms.com/
COMMENT=	Light Color Management System -- a color management library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check

CONFIGURE_ARGS+=	--without-jpeg
CONFIGURE_ARGS+=	--without-tiff
CONFIGURE_ARGS+=	--without-zlib

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

PKGCONFIG_OVERRIDE=	lcms.pc.in

INSTALLATION_DIRS+=	share/doc/lcms

post-install:
.for _f_ in LCMSAPI.TXT TUTORIAL.TXT
	${INSTALL_DATA} ${WRKSRC}/doc/${_f_} ${PREFIX}/share/doc/lcms/${_f_}
.endfor

.include "../../mk/bsd.pkg.mk"
