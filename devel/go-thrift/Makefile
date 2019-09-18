# $NetBSD: Makefile,v 1.1 2019/09/18 11:27:52 adam Exp $

.include "../../devel/thrift/Makefile.version"

PKGNAME=	go-${DISTNAME}
COMMENT=	Go bindings for the Apache Thrift RPC system

EXTRACT_ELEMENTS=	${DISTNAME}/lib/go

GO_SRCPATH=	github.com/apache/thrift/lib/go/thrift
GO_DIST_BASE=	${DISTNAME}/lib/go/thrift

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
