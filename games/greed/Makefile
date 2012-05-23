# $NetBSD: Makefile,v 1.4 2012/05/23 05:58:17 dholland Exp $
#

DISTNAME=		greed-3.4
PKGREVISION=		1
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
