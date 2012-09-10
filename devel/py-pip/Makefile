# $NetBSD: Makefile,v 1.3 2012/09/10 14:01:28 wen Exp $
#

DISTNAME=	pip-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/p/pip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pip-installer.org/
COMMENT=	Installs Python packages as an easy_install replacement
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SUBST+=		PYVERSSUFFIX="${PYVERSSUFFIX}"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
