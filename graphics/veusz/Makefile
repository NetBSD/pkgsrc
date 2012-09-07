# $NetBSD: Makefile,v 1.31 2012/09/07 19:16:54 adam Exp $
#

DISTNAME=		veusz-1.16
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://download.gna.org/veusz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://home.gna.org/veusz/
COMMENT=		Scientific plotting package
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes
USE_LANGUAGES=		c c++

REPLACE_PYTHON=		examples/embedexample.py

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/py-sip/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
