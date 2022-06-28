# $NetBSD: Makefile,v 1.6 2022/06/28 11:33:55 wiz Exp $

DISTNAME=	uw-ttyp0-1.3
PKGREVISION=	5
CATEGORIES=	fonts
MASTER_SITES=	https://people.mpi-inf.mpg.de/~uwe/misc/uw-ttyp0/

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://people.mpi-inf.mpg.de/~uwe/misc/uw-ttyp0/
COMMENT=	Monospace bitmap screen fonts for X11
LICENSE=	ttyp0-license AND mit

TOOL_DEPENDS+=	bdftopcf-[0-9]*:../../fonts/bdftopcf

USE_TOOLS+=	gmake perl gzip
USE_LANGUAGES=	# none

HAS_CONFIGURE=	yes

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	PCFDIR=${PREFIX}/share/fonts/X11/uw-ttyp0

# Otherwise fontconfig picks fonts with less character support...
MAKE_FLAGS+=	ENCODINGS=uni

.include "../../mk/bsd.pkg.mk"
