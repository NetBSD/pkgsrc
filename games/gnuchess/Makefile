# $NetBSD: Makefile,v 1.20 2004/01/24 13:30:56 grant Exp $
# FreeBSD Id: Makefile,v 1.6 1999/01/27 07:41:12 fenner Exp
#

DISTNAME=	chess-5.00
PKGNAME=	gnuchess-5.00
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=chess/}

PATCHFILES=	gnu500+.patch
PATCH_SITES=	http://www.tim-mann.org/xboard/
PATCH_DIST_ARGS=	-d ${WRKDIR}/${DISTNAME} --quiet -E ${PATCH_STRIP}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/chess/chess.html
COMMENT=	GNU chess engine

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
ALL_TARGET=	gnuchess

BOOKDIR=	${PREFIX}/lib/gnuchess
DOCDIR=		${PREFIX}/share/doc/gnuchess

# powerpc has problems with anything >= -O2 here
.if (${MACHINE_ARCH} == "powerpc")
CONFIGURE_ENV+=		CFLAGS="-O -Winline -Wmissing-prototypes -funroll-loops"
.else
CONFIGURE_ENV+=         CFLAGS="-O3 -Winline -Wmissing-prototypes -funroll-loops -fomit-frame-pointer"
.endif

post-build:
	${SED} -e "s|@PREFIX@|${PREFIX}|g"				\
		${FILESDIR}/gnuchessx.sh > ${WRKDIR}/gnuchessx.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gnuchess ${PREFIX}/bin/gnuchess
	${INSTALL_SCRIPT} ${WRKDIR}/gnuchessx.sh ${PREFIX}/bin/gnuchessx
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/README ${DOCDIR}
	${INSTALL_DATA_DIR} ${BOOKDIR}
	${TOUCH} ${BOOKDIR}/.directory

.include "../../mk/bsd.pkg.mk"
