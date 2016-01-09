# $NetBSD: Makefile,v 1.3 2016/01/09 22:38:27 wiz Exp $

DISTNAME=		linecache2-1.0.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel python
MASTER_SITES=		http://pypi.python.org/packages/source/l/linecache2/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pypi.python.org/pypi/linecache2
COMMENT=		Backport of the linecache module to older Python versions
LICENSE=		python-software-foundation

DEPENDS+=		${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr

# https://github.com/testing-cabal/linecache2/issues/2
# https://bugs.python.org/issue24054
post-extract:
	${RM} ${WRKSRC}/linecache2/tests/inspect_fodder2.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
