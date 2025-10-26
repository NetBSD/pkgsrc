# $NetBSD: Makefile,v 1.9 2025/10/26 12:03:28 nia Exp $

DISTNAME=	uw-ttyp0-2.1
CATEGORIES=	fonts
MASTER_SITES=	https://people.mpi-inf.mpg.de/~uwe/misc/uw-ttyp0/

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://people.mpi-inf.mpg.de/~uwe/misc/uw-ttyp0/
COMMENT=	Monospace bitmap screen fonts for X11
LICENSE=	ttyp0-license AND mit

USE_TOOLS+=	gmake perl gzip
USE_LANGUAGES=	# none

HAS_CONFIGURE=	yes

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	PCFDIR=${PREFIX}/share/fonts/X11/uw-ttyp0

# seems to segfault
MAKE_FLAGS+=	GEN_OTB=0

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} != "native"
TOOL_DEPENDS+=	bdftopcf-[0-9]*:../../fonts/bdftopcf
TOOL_DEPENDS+=	mkfontscale-[0-9]*:../../fonts/mkfontscale
.endif

.if ${OPSYS} == "Linux"
TOOL_DEPENDS+=	bdf2psf-[0-9]*:../../converters/bdf2psf
MAKE_FLAGS+=	GEN_CONS_LINUX=1

CONFIGURE_ARGS+=	--conslinuxnaming=console-setup
CONFIGURE_ARGS+=	--conslinuxdir=${PREFIX}/share/consolefonts
.endif

MAKE_FLAGS.NetBSD+=	GEN_CONS_NETBSD=1

CONFIGURE_ARGS.NetBSD+=	--consnbsddir=${PREFIX}/share/examples/wsfont

.include "../../mk/bsd.pkg.mk"
