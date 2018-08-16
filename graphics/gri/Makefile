# $NetBSD: Makefile,v 1.62 2018/08/16 18:54:52 adam Exp $

DISTNAME=	gri-2.12.23
PKGREVISION=	17
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gri/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gri.sourceforge.net/
COMMENT=	Language for scientific graphics applications
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=		ImageMagick-[0-9]*:../../graphics/ImageMagick
BUILD_DEPENDS+=		dvipsk-[0-9]*:../../print/dvipsk
BUILD_DEPENDS+=		tex-tex-[0-9]*:../../print/tex-tex
BUILD_DEPENDS+=		p5-Perl4-CoreLibs-[0-9]*:../../devel/p5-Perl4-CoreLibs

USE_LANGUAGES=		c c++03
USE_TOOLS+=		aclocal autoconf automake gmake gs:run makeinfo perl
GNU_CONFIGURE=		yes
REPLACE_PERL+=		src/gri_merge src/gri_unpage
INFO_FILES=		yes
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} PKGINFODIR=${PKGINFODIR}

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../devel/netcdf/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
