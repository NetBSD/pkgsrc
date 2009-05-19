# $NetBSD: Makefile,v 1.31 2009/05/19 08:59:17 wiz Exp $

DISTNAME=	lcms-1.18a
# 1.18a is a bugfix semi-release after 1.18, and it's just 1.18 with a
# security patch
PKGNAME=	lcms-1.18.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.littlecms.com/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.littlecms.com/
COMMENT=	Little Color Management System -- a color management library
# This is very MIT-like, but perhaps not the exact text.
#LICENSE=	lcms-license

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

# lcms-1.18a should unpack to lcms-1.18a, but it isn't really a normal
# release
WRKSRC=		${WRKDIR}/lcms-1.18

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
TEST_TARGET=		check

# lcms does not need zlib, but will look for it and link it to tifficc
# if present.  Therefore, we don't enjoin lcms from finding zlib, but
# don't include it via bl3.

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE:Q}

PKGCONFIG_OVERRIDE=	lcms.pc.in

INSTALLATION_DIRS+=	share/doc/lcms

post-install:
.for _f_ in LCMSAPI.TXT TUTORIAL.TXT
	${INSTALL_DATA} ${WRKSRC}/doc/${_f_} ${DESTDIR}${PREFIX}/share/doc/lcms/${_f_}
.endfor

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
