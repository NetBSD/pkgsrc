# $NetBSD: Makefile,v 1.7 2010/02/05 11:42:37 drochner Exp $

DISTNAME=	babl-0.1.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/babl/0.1/ \
		http://ftp.gwdg.de/pub/misc/grafik/gimp/babl/0.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://gegl.org/babl/
COMMENT=	Dynamic pixel conversion library
###
### NOTE: to build documentation--which requires additional dependencies--
###	  define BUILD_DOCS in MAKE_ENV.
###
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	babl.pc.in

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
