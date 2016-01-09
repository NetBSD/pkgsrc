# $NetBSD: Makefile,v 1.1 2016/01/09 13:30:21 wiz Exp $

DISTNAME=		linecache2-1.0.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=		http://pypi.python.org/packages/source/l/linecache2/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pypi.python.org/pypi/linecache2
COMMENT=		Backport of the linecache module to older Python versions
LICENSE=		python-software-foundation

DEPENDS+=		${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
