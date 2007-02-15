# $NetBSD: Makefile,v 1.32 2007/02/15 14:58:21 joerg Exp $

DISTNAME=		gri-2.12.5
PKGREVISION=	3
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gri/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gri.sourceforge.net/
COMMENT=		Language for scientific graphics applications

BUILD_DEPENDS+=		ImageMagick-[0-9]*:../../graphics/ImageMagick

BROKEN_IN=		pkgsrc-2006Q4

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake gs:run makeinfo perl
REPLACE_PERL+=		gri_merge gri_unpage
INFO_FILES=		# PLIST
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} INFO_DIR=${PREFIX:Q}/${PKGINFODIR:Q}

.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
