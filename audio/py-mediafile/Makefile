# $NetBSD: Makefile,v 1.2 2022/01/04 20:52:34 wiz Exp $

DISTNAME=	mediafile-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	https://files.pythonhosted.org/packages/b9/ab/14e45cb4869aa3bf91d82e2fac66101e4a00e7e0b2af5e04ab5e06c49e1d/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/beetbox/mediafile
COMMENT=	Handles low-level interfacing for files' tags. Wraps Mutagen to
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.9:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.45:../../audio/py-mutagen

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
