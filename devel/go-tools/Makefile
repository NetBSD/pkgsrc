# $NetBSD: Makefile,v 1.65 2022/07/13 16:03:08 bsiegert Exp $

DISTNAME=		tools-0.1.0
PKGNAME=		go-${DISTNAME}
PKGREVISION=		14
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		tools
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		https://golang.org/
COMMENT=		Tools for use with Go, including godoc
LICENSE=		modified-bsd

GO_BUILD_PATTERN=	./cmd/...

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
CHECK_RELRO_SKIP+=	bin/authtest
CHECK_RELRO_SKIP+=	bin/benchcmp
CHECK_RELRO_SKIP+=	bin/bundle
CHECK_RELRO_SKIP+=	bin/callgraph
CHECK_RELRO_SKIP+=	bin/compilebench
CHECK_RELRO_SKIP+=	bin/cookieauth
CHECK_RELRO_SKIP+=	bin/cover
CHECK_RELRO_SKIP+=	bin/digraph
CHECK_RELRO_SKIP+=	bin/eg
CHECK_RELRO_SKIP+=	bin/fiximports
CHECK_RELRO_SKIP+=	bin/getgo
CHECK_RELRO_SKIP+=	bin/gitauth
CHECK_RELRO_SKIP+=	bin/go-contrib-init
CHECK_RELRO_SKIP+=	bin/godex
CHECK_RELRO_SKIP+=	bin/godoc
CHECK_RELRO_SKIP+=	bin/goimports
CHECK_RELRO_SKIP+=	bin/gomvpkg
CHECK_RELRO_SKIP+=	bin/gorename
CHECK_RELRO_SKIP+=	bin/gotype
CHECK_RELRO_SKIP+=	bin/goyacc
CHECK_RELRO_SKIP+=	bin/guru
CHECK_RELRO_SKIP+=	bin/html2article
CHECK_RELRO_SKIP+=	bin/netrcauth
CHECK_RELRO_SKIP+=	bin/present
CHECK_RELRO_SKIP+=	bin/present2md
CHECK_RELRO_SKIP+=	bin/server
CHECK_RELRO_SKIP+=	bin/splitdwarf
CHECK_RELRO_SKIP+=	bin/ssadump
CHECK_RELRO_SKIP+=	bin/stress
CHECK_RELRO_SKIP+=	bin/stringer
CHECK_RELRO_SKIP+=	bin/toolstash

pre-patch:
	${RM} -rf ${WRKSRC}/cmd/getgo/server

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
