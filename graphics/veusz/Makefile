# $NetBSD: Makefile,v 1.23 2011/11/01 06:01:48 sbd Exp $
#

DISTNAME=		veusz-1.12
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://download.gna.org/veusz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://home.gna.org/veusz/
COMMENT=		Scientific plotting package

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes
USE_LANGUAGES=		c c++

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
