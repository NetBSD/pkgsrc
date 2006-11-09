# $NetBSD: Makefile,v 1.10 2006/11/09 21:12:05 drochner Exp $
#

DISTNAME=		kye-0.9.2
CATEGORIES=		games
MASTER_SITES=		http://games.moria.org.uk/kye/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://games.moria.org.uk/kye/pygtk
COMMENT=		Puzzle game

PYDISTUTILSPKG=	yes
SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	kye/common.py
SUBST_SED.prefix=	's|@PREFIX@|${PREFIX}|g'

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
