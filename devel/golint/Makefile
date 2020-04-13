# $NetBSD: Makefile,v 1.29 2020/04/13 18:12:33 bsiegert Exp $

DISTNAME=		golint-20200301
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		lint
GITHUB_TAG=		738671d3881b9731cc63024d5d88cf28db875626

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		https://golang.org/
COMMENT=		Linter for Go source files
LICENSE=		modified-bsd

GO_BUILD_PATTERN=	./golint

CHECK_RELRO_SKIP+=	bin/golint

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/golint ${DESTDIR}${PREFIX}/bin

GO_MODULE_FILES+=	golang.org/x/crypto/@v/v0.0.0-20191011191535-87dc89f01550.mod
GO_MODULE_FILES+=	golang.org/x/crypto/@v/v0.0.0-20190308221718-c2843e01d9a2.mod
GO_MODULE_FILES+=	golang.org/x/xerrors/@v/v0.0.0-20191011141410-1b5146add898.mod
GO_MODULE_FILES+=	golang.org/x/sys/@v/v0.0.0-20190215142949-d0b11bdaac8a.mod
GO_MODULE_FILES+=	golang.org/x/sys/@v/v0.0.0-20190412213103-97732733099d.mod
GO_MODULE_FILES+=	golang.org/x/mod/@v/v0.1.1-0.20191105210325-c90efee705ee.mod
GO_MODULE_FILES+=	golang.org/x/text/@v/v0.3.0.mod
GO_MODULE_FILES+=	golang.org/x/sync/@v/v0.0.0-20190423024810-112230192c58.mod
GO_MODULE_FILES+=	golang.org/x/tools/@v/v0.0.0-20200130002326-2f3ba24bd6e7.mod
GO_MODULE_FILES+=	golang.org/x/net/@v/v0.0.0-20190620200207-3b0461eec859.mod
GO_MODULE_FILES+=	golang.org/x/net/@v/v0.0.0-20190404232315-eb5bcb51f2a3.mod
GO_MODULE_FILES+=	golang.org/x/tools/@v/v0.0.0-20200130002326-2f3ba24bd6e7.zip

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
