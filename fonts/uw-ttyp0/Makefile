# $NetBSD: Makefile,v 1.1 2020/06/17 11:06:28 nia Exp $

DISTNAME=	uw-ttyp0-1.3
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

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/fonts/X11/misc/fonts.*

.include "../../mk/bsd.pkg.mk"
