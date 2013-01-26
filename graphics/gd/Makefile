# $NetBSD: Makefile,v 1.91 2013/01/26 21:36:27 adam Exp $

DISTNAME=	gd-2.0.35
PKGREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	http://www.libgd.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.libgd.org/
COMMENT=	Graphics library for the dynamic creation of images

.include "options.mk"

# fails in test not finding libgd.a
MAKE_JOBS_SAFE=		no

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
REPLACE_PERL+=		bdftogd
PTHREAD_AUTO_VARS=	yes

# Make sure configure doesn't find an old (possibly non-Pkgsrc)
# libpng12-config executable.  If it does, it will override the Pkgsrc
# version, but fail to configure, and fail to build in PNG support.
CONFIGURE_ENV+=		ac_cv_path_LIBPNG12_CONFIG=""

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
