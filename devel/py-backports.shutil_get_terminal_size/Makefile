# $NetBSD: Makefile,v 1.1 2017/04/23 04:32:41 markd Exp $

DISTNAME=	backports.shutil_get_terminal_size-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.shutil_get_terminal_size/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chrippa/backports.shutil_get_terminal_size/
COMMENT=	Backport of the get_terminal_size function from Python 3.3's shutil
LICENSE=	mit

PYTHON_VERSIONS_ACCEPTED=	27

post-install:
	rm ${DESTDIR}${PREFIX}/${PYSITELIB}/backports/__init__.*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
