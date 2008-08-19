# $NetBSD: Makefile,v 1.1.1.1 2008/08/19 17:51:14 bjs Exp $
#

DISTNAME=	babl-${BABL_VERSION}
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/babl/0.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://gegl.org/babl/
COMMENT=	Dynamic pixel conversion library
###
### NOTE: to build documentation--which requires additional dependencies--
###	  define BUILD_DOCS in MAKE_ENV.
###
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake

PKGCONFIG_OVERRIDE+=	babl.pc.in

.include "Makefile.version"

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
