# $NetBSD: Makefile,v 1.21 2004/03/08 03:04:36 minskim Exp $
# FreeBSD Id: Makefile,v 1.6 1999/01/27 07:41:12 fenner Exp
#

DISTNAME=	gnuchess-5.07
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=chess/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/chess/chess.html
COMMENT=	GNU chess engine

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make

BOOKDIR=	${PREFIX}/lib/gnuchess
DOCDIR=		${PREFIX}/share/doc/gnuchess

# powerpc has problems with anything >= -O2 here
.if (${MACHINE_ARCH} == "powerpc")
CONFIGURE_ENV+=		CFLAGS="-O -Winline -Wmissing-prototypes -funroll-loops"
.else
CONFIGURE_ENV+=         CFLAGS="-O3 -Winline -Wmissing-prototypes -funroll-loops -fomit-frame-pointer"
.endif

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
