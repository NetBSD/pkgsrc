# $NetBSD: Makefile,v 1.13 2009/03/05 18:51:29 joerg Exp $
#

DISTNAME=	python-biggles-1.6.3
PKGNAME=	${PYPKGPREFIX}${DISTNAME:S/python//}
PKGREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=biggles/}

MAINTAINER=	Kai.Puolamaki@iki.fi
HOMEPAGE=	http://biggles.sourceforge.net/
COMMENT=	Python module for creating 2D scientific plots

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../graphics/plotutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
