# $NetBSD: Makefile,v 1.17 2008/01/18 05:06:36 tnn Exp $
#

DISTNAME=		kye-0.9.3
PKGREVISION=		6
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
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
