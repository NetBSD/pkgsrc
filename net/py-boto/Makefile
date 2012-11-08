# $NetBSD: Makefile,v 1.18 2012/11/08 19:27:12 jakllsch Exp $
#

DISTNAME=	boto-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://cloud.github.com/downloads/boto/boto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.pythonboto.org/
COMMENT=	Python interface to Amazon web services
LICENSE=	mit

REPLACE_PYTHON+=	*.py
REPLACE_PYTHON+=	boto/*/*.py
REPLACE_PYTHON+=	bin/*

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
