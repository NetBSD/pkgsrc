# $NetBSD: Makefile,v 1.16 2012/10/03 22:14:02 wiz Exp $
#

DISTNAME=	boto-2.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://cloud.github.com/downloads/boto/boto/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://docs.pythonboto.org/
COMMENT=	Python interface to Amazon web services
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PYTHON+=	*.py
REPLACE_PYTHON+=	boto/*/*.py
REPLACE_PYTHON+=	bin/*

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
