# $NetBSD: Makefile,v 1.5 2008/01/13 16:03:48 wiz Exp $
#

DISTNAME=		monsterz-0.7.1
CATEGORIES=		games
MASTER_SITES=		http://sam.zoy.org/monsterz/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://sam.zoy.org/monsterz/
COMMENT=		Puzzle game similar to the famous Bejeweled or Zookeeper

DEPENDS+=		${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game
DEPENDS+=		${PYPKGPREFIX}-Numeric-[0-9]*:../../math/py-Numeric

PYTHON_PATCH_SCRIPTS=	monsterz.py

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
