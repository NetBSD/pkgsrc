# $NetBSD: Makefile,v 1.1.1.1 2006/12/17 10:33:11 wiz Exp $
#

DISTNAME=		monsterz-0.7.0
CATEGORIES=		games
MASTER_SITES=		http://sam.zoy.org/monsterz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sam.zoy.org/monsterz/
COMMENT=		Puzzle game similar to the famous Bejeweled or Zookeeper

DEPENDS+=		${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game
DEPENDS+=		${PYPKGPREFIX}-Numeric-[0-9]*:../../math/py-Numeric

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
