# $NetBSD: Makefile,v 1.71 2020/06/02 08:23:54 adam Exp $

DISTNAME=		kye-1.0
PKGREVISION=		32
CATEGORIES=		games
MASTER_SITES=		http://games.moria.org.uk/kye/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://games.moria.org.uk/kye/pygtk
COMMENT=		Puzzle game

PYDISTUTILSPKG=		yes
SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	kye/common.py
SUBST_SED.prefix=	's|@PREFIX@|${PREFIX}|g'

PYTHON_VERSIONS_ACCEPTED=	27 # py-gtk2

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
