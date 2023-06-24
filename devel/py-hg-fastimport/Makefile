# $NetBSD: Makefile,v 1.19 2023/06/24 20:26:41 wiz Exp $

DISTNAME=	hg-fastimport-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://roy.marples.name/downloads/hg-fastimport/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	https://wiki.mercurial-scm.org/FastImportExtension
COMMENT=	Mercurial extension for importing from a git fast-import stream
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mercurial>=5.1:../../devel/py-mercurial

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
