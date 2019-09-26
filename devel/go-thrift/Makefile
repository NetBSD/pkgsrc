# $NetBSD: Makefile,v 1.2 2019/09/26 20:10:49 bsiegert Exp $

PKGREVISION= 1
.include "../../devel/thrift/Makefile.version"

PKGNAME=	go-${DISTNAME}
COMMENT=	Go bindings for the Apache Thrift RPC system

EXTRACT_ELEMENTS=	${DISTNAME}/lib/go

GO_SRCPATH=	github.com/apache/thrift/lib/go/thrift
GO_DIST_BASE=	${DISTNAME}/lib/go/thrift

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
