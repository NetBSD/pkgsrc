# $NetBSD: Makefile,v 1.1 2014/10/09 09:10:47 khorben Exp $

PROTOBUF_VERSION=2.5.0
DISTNAME=	protobuf-${PROTOBUF_VERSION}
PKGNAME=	${PYPKGPREFIX}-protobuf-${PROTOBUF_VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://protobuf.googlecode.com/files/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://code.google.com/p/protobuf/
COMMENT=	Google protocol buffers
LICENSE=	modified-bsd

PYSETUPSUBDIR=	python

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
