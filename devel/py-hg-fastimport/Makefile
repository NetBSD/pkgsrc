# $NetBSD: Makefile,v 1.25 2025/11/01 15:30:18 roy Exp $

DISTNAME=	hg-fastimport-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://foss.heptapod.net/mercurial/hg-fastimport/-/archive/0.1.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	https://wiki.mercurial-scm.org/FastImportExtension
COMMENT=	Mercurial extension for importing from a git fast-import stream
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-mercurial>=5.1:../../devel/py-mercurial

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
