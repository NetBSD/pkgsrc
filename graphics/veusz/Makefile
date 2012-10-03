# $NetBSD: Makefile,v 1.32.2.1 2012/10/03 12:08:16 spz Exp $
#

DISTNAME=		veusz-1.16
PKGREVISION=		3
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
