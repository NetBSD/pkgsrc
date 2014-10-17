# $NetBSD: Makefile,v 1.3 2014/10/17 22:13:24 joerg Exp $

.include "../../devel/protobuf/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://protobuf.googlecode.com/files/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://code.google.com/p/protobuf/
COMMENT=	Google protocol buffers
LICENSE=	modified-bsd

PYSETUPSUBDIR=	python

PYTHON_VERSIONS_INCOMPATIBLE=	33 34

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
