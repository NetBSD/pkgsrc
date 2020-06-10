# $NetBSD: Makefile,v 1.4 2020/06/10 18:02:37 wiz Exp $
#
# Release notes:
# https://github.com/golang/go/issues/33030

DISTNAME=	gopls-0.4.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=	tools
GITHUB_TAG=	gopls/v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://pkg.go.dev/golang.org/x/tools/gopls
COMMENT=	LSP server for Go editor integration
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/tools-${GITHUB_TAG:S/\//-/}/gopls

GO_BUILD_PATTERN=	.

CHECK_RELRO_SKIP+=	bin/gopls

GO_MODULE_FILES+=	github.com/!burnt!sushi/toml/@v/v0.3.1.mod
GO_MODULE_FILES+=	github.com/!burnt!sushi/toml/@v/v0.3.1.zip
GO_MODULE_FILES+=	github.com/davecgh/go-spew/@v/v1.1.0.mod
GO_MODULE_FILES+=	github.com/davecgh/go-spew/@v/v1.1.1.mod
GO_MODULE_FILES+=	github.com/google/renameio/@v/v0.1.0.mod
GO_MODULE_FILES+=	github.com/kisielk/gotool/@v/v1.0.0.mod
GO_MODULE_FILES+=	github.com/kr/pretty/@v/v0.1.0.mod
GO_MODULE_FILES+=	github.com/kr/pty/@v/v1.1.1.mod
GO_MODULE_FILES+=	github.com/kr/text/@v/v0.1.0.mod
GO_MODULE_FILES+=	github.com/pmezard/go-difflib/@v/v1.0.0.mod
GO_MODULE_FILES+=	github.com/rogpeppe/go-internal/@v/v1.3.0.mod
GO_MODULE_FILES+=	github.com/sergi/go-diff/@v/v1.1.0.mod
GO_MODULE_FILES+=	github.com/sergi/go-diff/@v/v1.1.0.zip
GO_MODULE_FILES+=	github.com/stretchr/objx/@v/v0.1.0.mod
GO_MODULE_FILES+=	github.com/stretchr/testify/@v/v1.4.0.mod
GO_MODULE_FILES+=	github.com/yuin/goldmark/@v/v1.1.27.mod
GO_MODULE_FILES+=	golang.org/x/crypto/@v/v0.0.0-20190308221718-c2843e01d9a2.mod
GO_MODULE_FILES+=	golang.org/x/crypto/@v/v0.0.0-20190510104115-cbcb75029529.mod
GO_MODULE_FILES+=	golang.org/x/crypto/@v/v0.0.0-20191011191535-87dc89f01550.mod
GO_MODULE_FILES+=	golang.org/x/mod/@v/v0.0.0-20190513183733-4bf6d317e70e.mod
GO_MODULE_FILES+=	golang.org/x/mod/@v/v0.2.0.mod
GO_MODULE_FILES+=	golang.org/x/mod/@v/v0.2.0.zip
GO_MODULE_FILES+=	golang.org/x/net/@v/v0.0.0-20190404232315-eb5bcb51f2a3.mod
GO_MODULE_FILES+=	golang.org/x/net/@v/v0.0.0-20200226121028-0de0cce0169b.mod
GO_MODULE_FILES+=	golang.org/x/sync/@v/v0.0.0-20190911185100-cd5d95a43a6e.mod
GO_MODULE_FILES+=	golang.org/x/sync/@v/v0.0.0-20190911185100-cd5d95a43a6e.zip
GO_MODULE_FILES+=	golang.org/x/sys/@v/v0.0.0-20190215142949-d0b11bdaac8a.mod
GO_MODULE_FILES+=	golang.org/x/sys/@v/v0.0.0-20190412213103-97732733099d.mod
GO_MODULE_FILES+=	golang.org/x/text/@v/v0.3.0.mod
GO_MODULE_FILES+=	golang.org/x/xerrors/@v/v0.0.0-20191011141410-1b5146add898.mod
GO_MODULE_FILES+=	golang.org/x/xerrors/@v/v0.0.0-20191204190536-9bdfabe68543.mod
GO_MODULE_FILES+=	golang.org/x/xerrors/@v/v0.0.0-20191204190536-9bdfabe68543.zip
GO_MODULE_FILES+=	gopkg.in/check.v1/@v/v0.0.0-20161208181325-20d25e280405.mod
GO_MODULE_FILES+=	gopkg.in/check.v1/@v/v1.0.0-20180628173108-788fd7840127.mod
GO_MODULE_FILES+=	gopkg.in/check.v1/@v/v1.0.0-20190902080502-41f04d3bba15.mod
GO_MODULE_FILES+=	gopkg.in/errgo.v2/@v/v2.1.0.mod
GO_MODULE_FILES+=	gopkg.in/yaml.v2/@v/v2.2.2.mod
GO_MODULE_FILES+=	gopkg.in/yaml.v2/@v/v2.2.4.mod
GO_MODULE_FILES+=	honnef.co/go/tools/@v/v0.0.1-2020.1.3.mod
GO_MODULE_FILES+=	honnef.co/go/tools/@v/v0.0.1-2020.1.3.zip
GO_MODULE_FILES+=	mvdan.cc/xurls/v2/@v/v2.1.0.mod
GO_MODULE_FILES+=	mvdan.cc/xurls/v2/@v/v2.1.0.zip

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
