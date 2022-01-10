# $NetBSD: Makefile,v 1.2 2022/01/10 08:51:00 wiz Exp $

DISTNAME=	bz2file-0.98
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bz2file/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nvawda/bz2file
COMMENT=	Read and write bzip2-compressed files
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test_bz2file.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
