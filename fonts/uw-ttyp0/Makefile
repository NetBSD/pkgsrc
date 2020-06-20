# $NetBSD: Makefile,v 1.2 2020/06/20 16:13:30 nia Exp $

DISTNAME=	uw-ttyp0-1.3
PKGREVISION=	1
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

# Otherwise fontconfig picks fonts with less character support...
MAKE_FLAGS+=	ENCODINGS=uni

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/fonts/X11/misc/fonts.*

.include "../../mk/bsd.pkg.mk"
