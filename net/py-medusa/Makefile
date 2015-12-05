# $NetBSD: Makefile,v 1.7 2015/12/05 21:25:53 adam Exp $

DISTNAME=	medusa-0.5.4
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://www.amk.ca/files/python/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.amk.ca/python/code/medusa.html
COMMENT=	Framework for writing asynchronous socket-based servers

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
