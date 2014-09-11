# $NetBSD: Makefile,v 1.4 2014/09/11 13:49:06 joerg Exp $

DISTNAME=	hgnested-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://hgnested.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/hgnested/
COMMENT=	Mercurial extension to work with nested repositories
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-mercurial>=1.6:../../devel/py-mercurial

PYTHON_VERSIONS_INCOMPATIBLE=	33 34	# XXX: devel/py-mercurial

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
