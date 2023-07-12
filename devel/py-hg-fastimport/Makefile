# $NetBSD: Makefile,v 1.20 2023/07/12 19:09:22 wiz Exp $

DISTNAME=	hg-fastimport-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://roy.marples.name/downloads/hg-fastimport/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	https://wiki.mercurial-scm.org/FastImportExtension
COMMENT=	Mercurial extension for importing from a git fast-import stream
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-sqlite3>=0:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-mercurial>=5.1:../../devel/py-mercurial

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
