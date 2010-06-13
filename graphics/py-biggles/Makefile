# $NetBSD: Makefile,v 1.14 2010/06/13 22:44:42 wiz Exp $
#

DISTNAME=	python-biggles-1.6.3
PKGNAME=	${PYPKGPREFIX}${DISTNAME:S/python//}
PKGREVISION=	4
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
