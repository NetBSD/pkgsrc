# $NetBSD: Makefile,v 1.1 2016/08/17 13:38:28 richard Exp $

DISTNAME=		cycler-0.10.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics python
MASTER_SITES=		${MASTER_SITE_GITHUB:=matplotlib/}
GITHUB_PROJECT=		cycler
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://matplotlib.org/cycler
COMMENT=		Composable style cycles
LICENSE=		2-clause-bsd

DEPENDS+=		${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
