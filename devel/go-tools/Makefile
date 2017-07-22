# $NetBSD: Makefile,v 1.15 2017/07/22 19:32:40 wiz Exp $

DISTNAME=		tools
PKGNAME=		go-tools-1.8
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		${DISTNAME}
GITHUB_TAG=		2946dd1

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Tools for use with Go, including godoc
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/tools
GO_DIST_BASE=		${DISTNAME}-${GITHUB_TAG}*

USE_TOOLS+=		bash
REPLACE_BASH+=		cmd/godoc/setup-godoc-app.bash
REPLACE_BASH+=		cmd/toolstash/buildall

CHECK_RELRO_SKIP+=	bin/benchcmp
CHECK_RELRO_SKIP+=	bin/bundle
CHECK_RELRO_SKIP+=	bin/callgraph
CHECK_RELRO_SKIP+=	bin/cover
CHECK_RELRO_SKIP+=	bin/digraph
CHECK_RELRO_SKIP+=	bin/eg
CHECK_RELRO_SKIP+=	bin/fiximports
CHECK_RELRO_SKIP+=	bin/godex
CHECK_RELRO_SKIP+=	bin/godoc
CHECK_RELRO_SKIP+=	bin/goimports
CHECK_RELRO_SKIP+=	bin/gomvpkg
CHECK_RELRO_SKIP+=	bin/gorename
CHECK_RELRO_SKIP+=	bin/gotype
CHECK_RELRO_SKIP+=	bin/goyacc
CHECK_RELRO_SKIP+=	bin/guru
CHECK_RELRO_SKIP+=	bin/heapview
CHECK_RELRO_SKIP+=	bin/html2article
CHECK_RELRO_SKIP+=	bin/present
CHECK_RELRO_SKIP+=	bin/ssadump
CHECK_RELRO_SKIP+=	bin/stress
CHECK_RELRO_SKIP+=	bin/stringer
CHECK_RELRO_SKIP+=	bin/tip
CHECK_RELRO_SKIP+=	bin/toolstash

.include "../../lang/go/go-package.mk"
.include "../../devel/google-api-go-client/buildlink3.mk"
.include "../../security/go-crypto-acme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
