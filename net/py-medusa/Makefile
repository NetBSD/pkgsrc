# $NetBSD: Makefile,v 1.12 2019/04/26 13:14:09 maya Exp $

DISTNAME=	medusa-0.5.4
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://www.amk.ca/files/python/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.amk.ca/python/code/medusa.html
COMMENT=	Framework for writing asynchronous socket-based servers

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
