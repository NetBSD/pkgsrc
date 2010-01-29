# $NetBSD: Makefile,v 1.3 2010/01/29 23:08:08 joerg Exp $
#

DISTNAME=		greed-3.4
CATEGORIES=		games
MASTER_SITES=		http://www.catb.org/~esr/greed/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.catb.org/~esr/greed/
COMMENT=		Strategy game: eat as much as possible

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		greed
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
