# $NetBSD: Makefile,v 1.2 2006/01/24 07:32:09 wiz Exp $
#

DISTNAME=		kye-0.1.0
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://games.moria.org.uk/kye/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://games.moria.org.uk/kye/pygtk
COMMENT=		Puzzle game

PYDISTUTILSPKG=	yes
SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	Kye
SUBST_SED.prefix=	's|@PREFIX@|${PREFIX}|g'

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
