# $NetBSD: Makefile,v 1.25 2019/10/18 14:58:45 bsiegert Exp $

DISTNAME=		go-protobuf-1.3.2
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		protobuf
GITHUB_TAG=		v${PKGVERSION_NOREV}

HOMEPAGE=		http://godoc.org/${GO_SRCPATH}
COMMENT=		Go support for Google protocol buffers
LICENSE=		modified-bsd

GO_DIST_BASE=		${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=		github.com/golang/protobuf

.for godir in descriptor jsonpb proto protoc-gen-go ptypes
GO_BUILD_PATTERN+=	${GO_SRCPATH}/${godir}/...
.endfor

REPLACE_SH+=		regenerate.sh

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
