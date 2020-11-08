# $NetBSD: Makefile,v 1.8 2020/11/08 21:59:25 bsiegert Exp $

DISTNAME=	micro-2.0.7
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=zyedidia/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://micro-editor.github.io/
COMMENT=	Modern and intuitive terminal-based text editor
LICENSE=	mit

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

GO_BUILD_PATTERN=	./cmd/micro
GO_LDFLAGS+=		-X github.com/zyedidia/micro/v2/internal/util.Version=${PKGVERSION_NOREV}
GO_LDFLAGS+=		-X github.com/zyedidia/micro/v2/internal/util.CommitHash=${GITHUB_TAG}
GO_ARGS+=		-ldflags ${GO_LDFLAGS:Q}

GO_MODULE_FILES+=	github.com/blang/semver/@v/v3.5.1+incompatible.mod
GO_MODULE_FILES+=	github.com/blang/semver/@v/v3.5.1+incompatible.zip
GO_MODULE_FILES+=	github.com/chzyer/logex/@v/v1.1.10.mod
GO_MODULE_FILES+=	github.com/chzyer/logex/@v/v1.1.10.zip
GO_MODULE_FILES+=	github.com/chzyer/readline/@v/v0.0.0-20180603132655-2972be24d48e.mod
GO_MODULE_FILES+=	github.com/chzyer/readline/@v/v0.0.0-20180603132655-2972be24d48e.zip
GO_MODULE_FILES+=	github.com/chzyer/test/@v/v0.0.0-20180213035817-a1ea475d72b1.mod
GO_MODULE_FILES+=	github.com/chzyer/test/@v/v0.0.0-20180213035817-a1ea475d72b1.zip
GO_MODULE_FILES+=	github.com/davecgh/go-spew/@v/v1.1.0.mod
GO_MODULE_FILES+=	github.com/davecgh/go-spew/@v/v1.1.1.mod
GO_MODULE_FILES+=	github.com/davecgh/go-spew/@v/v1.1.1.zip
GO_MODULE_FILES+=	github.com/dustin/go-humanize/@v/v1.0.0.mod
GO_MODULE_FILES+=	github.com/dustin/go-humanize/@v/v1.0.0.zip
GO_MODULE_FILES+=	github.com/gdamore/encoding/@v/v1.0.0.mod
GO_MODULE_FILES+=	github.com/gdamore/encoding/@v/v1.0.0.zip
GO_MODULE_FILES+=	github.com/go-errors/errors/@v/v1.0.1.mod
GO_MODULE_FILES+=	github.com/go-errors/errors/@v/v1.0.1.zip
GO_MODULE_FILES+=	github.com/kr/pretty/@v/v0.1.0.mod
GO_MODULE_FILES+=	github.com/kr/pretty/@v/v0.1.0.zip
GO_MODULE_FILES+=	github.com/kr/pty/@v/v1.1.1.mod
GO_MODULE_FILES+=	github.com/kr/pty/@v/v1.1.1.zip
GO_MODULE_FILES+=	github.com/kr/text/@v/v0.1.0.mod
GO_MODULE_FILES+=	github.com/kr/text/@v/v0.1.0.zip
GO_MODULE_FILES+=	github.com/lucasb-eyer/go-colorful/@v/v1.0.3.mod
GO_MODULE_FILES+=	github.com/lucasb-eyer/go-colorful/@v/v1.0.3.zip
GO_MODULE_FILES+=	github.com/mattn/go-isatty/@v/v0.0.11.mod
GO_MODULE_FILES+=	github.com/mattn/go-isatty/@v/v0.0.11.zip
GO_MODULE_FILES+=	github.com/mitchellh/go-homedir/@v/v1.1.0.mod
GO_MODULE_FILES+=	github.com/mitchellh/go-homedir/@v/v1.1.0.zip
GO_MODULE_FILES+=	github.com/p-e-w/go-runewidth/@v/v0.0.10-0.20200613030200-3e1705c5c059.mod
GO_MODULE_FILES+=	github.com/p-e-w/go-runewidth/@v/v0.0.10-0.20200613030200-3e1705c5c059.zip
GO_MODULE_FILES+=	github.com/pmezard/go-difflib/@v/v1.0.0.mod
GO_MODULE_FILES+=	github.com/pmezard/go-difflib/@v/v1.0.0.zip
GO_MODULE_FILES+=	github.com/robertkrimen/otto/@v/v0.0.0-20191219234010-c382bd3c16ff.mod
GO_MODULE_FILES+=	github.com/robertkrimen/otto/@v/v0.0.0-20191219234010-c382bd3c16ff.zip
GO_MODULE_FILES+=	github.com/sergi/go-diff/@v/v1.1.0.mod
GO_MODULE_FILES+=	github.com/sergi/go-diff/@v/v1.1.0.zip
GO_MODULE_FILES+=	github.com/stretchr/objx/@v/v0.1.0.mod
GO_MODULE_FILES+=	github.com/stretchr/objx/@v/v0.1.0.zip
GO_MODULE_FILES+=	github.com/stretchr/testify/@v/v1.4.0.mod
GO_MODULE_FILES+=	github.com/stretchr/testify/@v/v1.4.0.zip
GO_MODULE_FILES+=	github.com/xo/terminfo/@v/v0.0.0-20200218205459-454e5b68f9e8.mod
GO_MODULE_FILES+=	github.com/xo/terminfo/@v/v0.0.0-20200218205459-454e5b68f9e8.zip
GO_MODULE_FILES+=	github.com/yuin/gopher-lua/@v/v0.0.0-20190206043414-8bfc7677f583.mod
GO_MODULE_FILES+=	github.com/yuin/gopher-lua/@v/v0.0.0-20191220021717-ab39c6098bdb.mod
GO_MODULE_FILES+=	github.com/yuin/gopher-lua/@v/v0.0.0-20191220021717-ab39c6098bdb.zip
GO_MODULE_FILES+=	github.com/zyedidia/clipboard/@v/v1.0.3.mod
GO_MODULE_FILES+=	github.com/zyedidia/clipboard/@v/v1.0.3.zip
GO_MODULE_FILES+=	github.com/zyedidia/glob/@v/v0.0.0-20170209203856-dd4023a66dc3.mod
GO_MODULE_FILES+=	github.com/zyedidia/glob/@v/v0.0.0-20170209203856-dd4023a66dc3.zip
GO_MODULE_FILES+=	github.com/zyedidia/go-shellquote/@v/v0.0.0-20200613203517-eccd813c0655.mod
GO_MODULE_FILES+=	github.com/zyedidia/go-shellquote/@v/v0.0.0-20200613203517-eccd813c0655.zip
GO_MODULE_FILES+=	github.com/zyedidia/highlight/@v/v0.0.0-20170330143449-201131ce5cf5.mod
GO_MODULE_FILES+=	github.com/zyedidia/highlight/@v/v0.0.0-20170330143449-201131ce5cf5.zip
GO_MODULE_FILES+=	github.com/zyedidia/json5/@v/v0.0.0-20200102012142-2da050b1a98d.mod
GO_MODULE_FILES+=	github.com/zyedidia/json5/@v/v0.0.0-20200102012142-2da050b1a98d.zip
GO_MODULE_FILES+=	github.com/zyedidia/poller/@v/v1.0.1.mod
GO_MODULE_FILES+=	github.com/zyedidia/poller/@v/v1.0.1.zip
GO_MODULE_FILES+=	github.com/zyedidia/pty/@v/v2.0.0+incompatible.mod
GO_MODULE_FILES+=	github.com/zyedidia/pty/@v/v2.0.0+incompatible.zip
GO_MODULE_FILES+=	github.com/zyedidia/tcell/v2/@v/v2.0.2.mod
GO_MODULE_FILES+=	github.com/zyedidia/tcell/v2/@v/v2.0.2.zip
GO_MODULE_FILES+=	github.com/zyedidia/terminal/@v/v0.0.0-20180726154117-533c623e2415.mod
GO_MODULE_FILES+=	github.com/zyedidia/terminal/@v/v0.0.0-20180726154117-533c623e2415.zip
GO_MODULE_FILES+=	golang.org/x/sys/@v/v0.0.0-20190204203706-41f3e6584952.mod
GO_MODULE_FILES+=	golang.org/x/sys/@v/v0.0.0-20190626150813-e07cf5db2756.mod
GO_MODULE_FILES+=	golang.org/x/sys/@v/v0.0.0-20191026070338-33540a1f6037.mod
GO_MODULE_FILES+=	golang.org/x/sys/@v/v0.0.0-20191026070338-33540a1f6037.zip
GO_MODULE_FILES+=	golang.org/x/text/@v/v0.3.0.mod
GO_MODULE_FILES+=	golang.org/x/text/@v/v0.3.2.mod
GO_MODULE_FILES+=	golang.org/x/text/@v/v0.3.2.zip
GO_MODULE_FILES+=	golang.org/x/tools/@v/v0.0.0-20180917221912-90fa682c2a6e.mod
GO_MODULE_FILES+=	golang.org/x/tools/@v/v0.0.0-20180917221912-90fa682c2a6e.zip
GO_MODULE_FILES+=	gopkg.in/check.v1/@v/v0.0.0-20161208181325-20d25e280405.mod
GO_MODULE_FILES+=	gopkg.in/check.v1/@v/v1.0.0-20190902080502-41f04d3bba15.mod
GO_MODULE_FILES+=	gopkg.in/check.v1/@v/v1.0.0-20190902080502-41f04d3bba15.zip
GO_MODULE_FILES+=	gopkg.in/sourcemap.v1/@v/v1.0.5.mod
GO_MODULE_FILES+=	gopkg.in/sourcemap.v1/@v/v1.0.5.zip
GO_MODULE_FILES+=	gopkg.in/yaml.v2/@v/v2.2.2.mod
GO_MODULE_FILES+=	gopkg.in/yaml.v2/@v/v2.2.4.mod
GO_MODULE_FILES+=	gopkg.in/yaml.v2/@v/v2.2.7.mod
GO_MODULE_FILES+=	gopkg.in/yaml.v2/@v/v2.2.7.zip
GO_MODULE_FILES+=	layeh.com/gopher-luar/@v/v1.0.7.mod
GO_MODULE_FILES+=	layeh.com/gopher-luar/@v/v1.0.7.zip

do-build:
	${RUN} cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install -v ${GO_ARGS} ${GO_BUILD_PATTERN}

post-install:
	${INSTALL_MAN} ${WRKSRC}/assets/packaging/micro.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
