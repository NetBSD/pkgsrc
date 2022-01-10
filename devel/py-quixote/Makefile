# $NetBSD: Makefile,v 1.15 2022/01/10 21:31:29 wiz Exp $

DISTNAME=	Quixote-2.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	devel www python
MASTER_SITES=	http://quixote.ca/releases/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://quixote.ca/
COMMENT=	Framework for writing Python web application
LICENSE=	mit

PYTHON_VERSIONS_ACCEPTED=	27 # v3.0 is for Python 3.x only

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
