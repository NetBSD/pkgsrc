# $NetBSD: Makefile,v 1.2 2016/01/09 22:36:45 wiz Exp $

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

post-extract:
	${RM} ${WRKSRC}/linecache2/tests/inspect_fodder2.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
