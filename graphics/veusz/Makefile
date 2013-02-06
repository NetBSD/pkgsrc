# $NetBSD: Makefile,v 1.37 2013/02/06 23:22:34 jperkin Exp $
#

DISTNAME=		veusz-1.16
PKGREVISION=		6
CATEGORIES=		graphics
MASTER_SITES=		http://download.gna.org/veusz/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://home.gna.org/veusz/
COMMENT=		Scientific plotting package
LICENSE=		gnu-gpl-v2

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
