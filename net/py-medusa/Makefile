# $NetBSD: Makefile,v 1.9 2017/01/01 14:43:51 wiz Exp $

DISTNAME=	medusa-0.5.4
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://www.amk.ca/files/python/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.amk.ca/python/code/medusa.html
COMMENT=	Framework for writing asynchronous socket-based servers

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
