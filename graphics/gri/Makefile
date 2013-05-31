# $NetBSD: Makefile,v 1.45 2013/05/31 12:41:06 wiz Exp $

DISTNAME=	gri-2.12.23
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gri/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gri.sourceforge.net/
COMMENT=	Language for scientific graphics applications
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=		ImageMagick-[0-9]*:../../graphics/ImageMagick
BUILD_DEPENDS+=		dvipsk-[0-9]*:../../print/dvipsk
BUILD_DEPENDS+=		tex-tex-[0-9]*:../../print/tex-tex

USE_LANGUAGES=		c c++
USE_TOOLS+=		aclocal autoconf automake gmake gs:run makeinfo perl
GNU_CONFIGURE=		yes
REPLACE_PERL+=		src/gri_merge src/gri_unpage
INFO_FILES=		yes
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} PKGINFODIR=${PKGINFODIR}

pre-configure:
	cd ${WRKSRC} && aclocal && autoconf

.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
