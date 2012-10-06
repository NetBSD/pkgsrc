# $NetBSD: Makefile,v 1.12 2012/10/06 14:10:41 asau Exp $

DISTNAME=	babl-0.1.10
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/babl/${PKGVERSION_NOREV:R}/ \
		http://ftp.gwdg.de/pub/misc/grafik/gimp/babl/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gegl.org/babl/
COMMENT=	Dynamic pixel conversion library
LICENSE=	gnu-gpl-v3

# NOTE: to build documentation (which requires additional dependencies)
#	define BUILD_DOCS in MAKE_ENV.

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	babl.pc.in

# XXX Clang does not handle assembler, yet
.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CONFIGURE_ARGS+=	--disable-sse
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
