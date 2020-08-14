# $NetBSD: Makefile,v 1.12 2020/08/14 20:01:35 bsiegert Exp $

PKGREVISION= 8
.include "../../devel/thrift/Makefile.version"

PKGNAME=	go-${DISTNAME}
COMMENT=	Go bindings for the Apache Thrift RPC system

EXTRACT_ELEMENTS=	${DISTNAME}/lib/go

GO_SRCPATH=	github.com/apache/thrift/lib/go/thrift
GO_DIST_BASE=	${DISTNAME}/lib/go/thrift

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
