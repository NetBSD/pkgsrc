# $NetBSD: Makefile,v 1.15 2015/08/14 18:27:06 wiz Exp $

DISTNAME=	babl_0.1.12.orig
PKGNAME=	babl-0.1.12
CATEGORIES=	graphics
MASTER_SITES=	https://launchpad.net/ubuntu/+archive/primary/+files/
# https://git.gnome.org/browse/babl/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gegl.org/babl/
COMMENT=	Dynamic pixel conversion library
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

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
