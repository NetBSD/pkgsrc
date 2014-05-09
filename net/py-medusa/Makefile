# $NetBSD: Makefile,v 1.6 2014/05/09 07:37:15 wiz Exp $

DISTNAME=	medusa-0.5.4
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://www.amk.ca/files/python/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.amk.ca/python/code/medusa.html
COMMENT=	Framework for writing asynchronous socket-based servers

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	33 34

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
