# $NetBSD: Makefile,v 1.24 2025/04/30 14:08:20 wiz Exp $

DISTNAME=	hg-fastimport-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel
# Temporary home until I can host it somewhere
MASTER_SITES=	https://www.netbsd.org/~roy
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	https://wiki.mercurial-scm.org/FastImportExtension
COMMENT=	Mercurial extension for importing from a git fast-import stream
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-mercurial>=5.1:../../devel/py-mercurial

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
