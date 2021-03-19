# $NetBSD: Makefile,v 1.18 2021/03/19 17:36:57 bsiegert Exp $

PKGREVISION= 14
.include "../../devel/thrift/Makefile.version"

PKGNAME=	go-${DISTNAME}
COMMENT=	Go bindings for the Apache Thrift RPC system

EXTRACT_ELEMENTS=	${DISTNAME}/lib/go

GO_SRCPATH=	github.com/apache/thrift/lib/go/thrift
GO_DIST_BASE=	${DISTNAME}/lib/go/thrift

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
