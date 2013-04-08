# $NetBSD: Makefile,v 1.37 2013/04/08 11:17:14 rodent Exp $

DISTNAME=	gnuchess-5.07
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=chess/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/chess/chess.html
COMMENT=	GNU chess engine

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes
USE_TOOLS+=	flex gmake

BOOKDIR=	${PREFIX}/lib/gnuchess
DOCDIR=		${PREFIX}/share/doc/gnuchess

# powerpc has problems with anything >= -O2 here
.if (${MACHINE_ARCH} == "powerpc")
CONFIGURE_ENV+=		CFLAGS="-O -Winline -Wmissing-prototypes -funroll-loops"
.else
CONFIGURE_ENV+=		CFLAGS="-O3 -Winline -Wmissing-prototypes -funroll-loops -fomit-frame-pointer"
.endif

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	src/book.h
SUBST_SED.paths=	-e 's,/usr/lib/games/,${LOCALBASE}/lib/,g'

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/README ${DESTDIR}${DOCDIR}

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
