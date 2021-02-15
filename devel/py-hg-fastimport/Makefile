# $NetBSD: Makefile,v 1.15 2021/02/15 14:39:15 roy Exp $

DISTNAME=	hg-fastimport-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://roy.marples.name/downloads/hg-fastimport/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	https://mercurial.selenic.com/wiki/FastImportExtension
COMMENT=	Mercurial extension for importing from a git fast-import stream
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mercurial>=5.1:../../devel/py-mercurial

PY_PATCHPLIST=			yes

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
