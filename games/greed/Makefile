# $NetBSD: Makefile,v 1.7 2015/08/18 07:31:08 wiz Exp $
#

DISTNAME=		greed-3.4
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		http://www.catb.org/~esr/greed/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.catb.org/~esr/greed/
COMMENT=		Strategy game: eat as much as possible

BUILD_TARGET=		greed
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

TERMLIB=		${BUILDLINK_LDADD.termcap} ${BUILDLINK_LDADD.curses}
MAKE_ENV+=		TERMLIB=${TERMLIB:Q}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
