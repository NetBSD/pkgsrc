# $NetBSD: Makefile,v 1.3 2022/01/04 20:52:52 wiz Exp $

DISTNAME=	backports.shutil_get_terminal_size-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.shutil_get_terminal_size/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chrippa/backports.shutil_get_terminal_size/
COMMENT=	Backport of the get_terminal_size function from Python 3.3's shutil
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-backports-[0-9]*:../../devel/py-backports

PYTHON_VERSIONS_ACCEPTED=	27

post-install:
	rm ${DESTDIR}${PREFIX}/${PYSITELIB}/backports/__init__.*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
