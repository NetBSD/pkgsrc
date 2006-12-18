# $NetBSD: Makefile,v 1.3 2006/12/18 16:32:57 drochner Exp $
#

DISTNAME=		monsterz-0.7.0
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
