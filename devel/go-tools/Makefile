# $NetBSD: Makefile,v 1.48 2021/01/23 14:23:03 bsiegert Exp $

DISTNAME=		tools
PKGNAME=		go-tools-1.15.20201026
PKGREVISION=		5
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		${DISTNAME}
GITHUB_TAG=		e84cfc6

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		https://golang.org/
COMMENT=		Tools for use with Go, including godoc
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/tools
GO_DIST_BASE=		${DISTNAME}-${GITHUB_TAG}*

USE_TOOLS+=		bash
REPLACE_BASH+=		cmd/getgo/*.bash
REPLACE_BASH+=		cmd/godoc/*.bash
REPLACE_BASH+=		cmd/toolstash/buildall
REPLACE_BASH+=		internal/lsp/reset_golden.sh

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
CHECK_RELRO_SKIP+=	bin/findcall
CHECK_RELRO_SKIP+=	bin/fiximports
CHECK_RELRO_SKIP+=	bin/genapijson
CHECK_RELRO_SKIP+=	bin/getgo
CHECK_RELRO_SKIP+=	bin/gitauth
CHECK_RELRO_SKIP+=	bin/go-contrib-init
CHECK_RELRO_SKIP+=	bin/godex
CHECK_RELRO_SKIP+=	bin/godoc
CHECK_RELRO_SKIP+=	bin/goimports
CHECK_RELRO_SKIP+=	bin/gomvpkg
CHECK_RELRO_SKIP+=	bin/gopackages
CHECK_RELRO_SKIP+=	bin/gorename
CHECK_RELRO_SKIP+=	bin/gostacks
CHECK_RELRO_SKIP+=	bin/gotype
CHECK_RELRO_SKIP+=	bin/goyacc
CHECK_RELRO_SKIP+=	bin/guru
CHECK_RELRO_SKIP+=	bin/helper
CHECK_RELRO_SKIP+=	bin/html2article
CHECK_RELRO_SKIP+=	bin/ifaceassert
CHECK_RELRO_SKIP+=	bin/lostcancel
CHECK_RELRO_SKIP+=	bin/netrcauth
CHECK_RELRO_SKIP+=	bin/nilness
CHECK_RELRO_SKIP+=	bin/present
CHECK_RELRO_SKIP+=	bin/present2md
CHECK_RELRO_SKIP+=	bin/server
CHECK_RELRO_SKIP+=	bin/shadow
CHECK_RELRO_SKIP+=	bin/splitdwarf
CHECK_RELRO_SKIP+=	bin/ssadump
CHECK_RELRO_SKIP+=	bin/stress
CHECK_RELRO_SKIP+=	bin/stringer
CHECK_RELRO_SKIP+=	bin/stringintconv
CHECK_RELRO_SKIP+=	bin/toolstash
CHECK_RELRO_SKIP+=	bin/unmarshal

pre-patch:
	${RM} -rf ${WRKSRC}/gopls ${WRKSRC}/cmd/getgo/server

.include "../../lang/go/go-package.mk"
.include "../../devel/go-mod/buildlink3.mk"
.include "../../devel/go-sync/buildlink3.mk"
.include "../../devel/go-xerrors/buildlink3.mk"
.include "../../devel/google-api-go-client/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.include "../../textproc/go-goldmark/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
