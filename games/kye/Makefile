# $NetBSD: Makefile,v 1.91 2024/05/29 16:32:41 adam Exp $

DISTNAME=		kye-1.0
PKGREVISION=		51
CATEGORIES=		games
MASTER_SITES=		http://games.moria.org.uk/kye/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://games.moria.org.uk/kye/download-install
COMMENT=		Puzzle game

PYDISTUTILSPKG=		yes
SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	kye/common.py
SUBST_SED.prefix=	's|@PREFIX@|${PREFIX}|g'

PYTHON_VERSIONS_ACCEPTED=	27 # py-gtk2

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
