# $NetBSD: Makefile,v 1.41 2016/07/07 14:49:25 jperkin Exp $

DISTNAME=	gnuchess-6.2.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU:=chess/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/chess/chess.html
COMMENT=	GNU chess engine
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	flex gmake

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--disable-nls

DOCDIR=			${PREFIX}/share/doc/gnuchess
INFO_FILES=		yes
INSTALLATION_DIRS=	${DOCDIR}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	src/book.h
SUBST_SED.paths=	-e 's,/usr/lib/games/,${PREFIX}/lib/,g'

post-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/README ${DESTDIR}${DOCDIR}

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
