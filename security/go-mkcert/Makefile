# $NetBSD: Makefile,v 1.20 2020/11/08 21:59:32 bsiegert Exp $

DISTNAME=		mkcert-${GITHUB_TAG}
PKGNAME=		go-mkcert-${VERSION}
PKGREVISION=		4
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=FiloSottile/}
GITHUB_PROJECT=		mkcert
VERSION=		1.4.1
GITHUB_TAG=		v${VERSION}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/FiloSottile/mkcert/
COMMENT=		Make locally trusted development certificates
LICENSE=		modified-bsd

WRKSRC=			${WRKDIR}/mkcert-${VERSION}
GO_BUILD_PATTERN=	github.com/FiloSottile/mkcert

INSTALLATION_DIRS+=	bin

GO_MODULE_FILES+=	software.sslmate.com/src/go-pkcs12/@v/v0.0.0-20180114231543-2291e8f0f237.mod
GO_MODULE_FILES+=	golang.org/x/tools/@v/v0.0.0-20191108193012-7d206e10da11.mod
GO_MODULE_FILES+=	golang.org/x/tools/@v/v0.0.0-20191022074931-774d2ec196ee.mod
GO_MODULE_FILES+=	golang.org/x/net/@v/v0.0.0-20190620200207-3b0461eec859.mod
GO_MODULE_FILES+=	golang.org/x/net/@v/v0.0.0-20190404232315-eb5bcb51f2a3.mod
GO_MODULE_FILES+=	golang.org/x/sync/@v/v0.0.0-20190423024810-112230192c58.mod
GO_MODULE_FILES+=	golang.org/x/xerrors/@v/v0.0.0-20190717185122-a985d3407aa7.mod
GO_MODULE_FILES+=	golang.org/x/crypto/@v/v0.0.0-20190308221718-c2843e01d9a2.mod
GO_MODULE_FILES+=	golang.org/x/crypto/@v/v0.0.0-20190510104115-cbcb75029529.mod
GO_MODULE_FILES+=	golang.org/x/sys/@v/v0.0.0-20190215142949-d0b11bdaac8a.mod
GO_MODULE_FILES+=	golang.org/x/sys/@v/v0.0.0-20190412213103-97732733099d.mod
GO_MODULE_FILES+=	golang.org/x/text/@v/v0.3.0.mod
GO_MODULE_FILES+=	golang.org/x/mod/@v/v0.0.0-20190513183733-4bf6d317e70e.mod
GO_MODULE_FILES+=	howett.net/plist/@v/v0.0.0-20181124034731-591f970eefbb.mod
GO_MODULE_FILES+=	honnef.co/go/tools/@v/v0.0.0-20191107024926-a9480a3ec3bc.mod
GO_MODULE_FILES+=	github.com/kisielk/gotool/@v/v1.0.0.mod
GO_MODULE_FILES+=	github.com/google/renameio/@v/v0.1.0.mod
GO_MODULE_FILES+=	github.com/rogpeppe/go-internal/@v/v1.3.0.mod
GO_MODULE_FILES+=	github.com/!burnt!sushi/toml/@v/v0.3.1.mod
GO_MODULE_FILES+=	github.com/kr/pretty/@v/v0.1.0.mod
GO_MODULE_FILES+=	github.com/kr/text/@v/v0.1.0.mod
GO_MODULE_FILES+=	github.com/kr/pty/@v/v1.1.1.mod
GO_MODULE_FILES+=	github.com/jessevdk/go-flags/@v/v1.4.0.mod
GO_MODULE_FILES+=	gopkg.in/yaml.v2/@v/v2.2.1.mod
GO_MODULE_FILES+=	gopkg.in/check.v1/@v/v1.0.0-20180628173108-788fd7840127.mod
GO_MODULE_FILES+=	gopkg.in/check.v1/@v/v0.0.0-20161208181325-20d25e280405.mod
GO_MODULE_FILES+=	gopkg.in/errgo.v2/@v/v2.1.0.mod
GO_MODULE_FILES+=	software.sslmate.com/src/go-pkcs12/@v/v0.0.0-20180114231543-2291e8f0f237.zip
GO_MODULE_FILES+=	golang.org/x/tools/@v/v0.0.0-20191108193012-7d206e10da11.zip
GO_MODULE_FILES+=	golang.org/x/net/@v/v0.0.0-20190620200207-3b0461eec859.zip
GO_MODULE_FILES+=	golang.org/x/sync/@v/v0.0.0-20190423024810-112230192c58.zip
GO_MODULE_FILES+=	golang.org/x/xerrors/@v/v0.0.0-20190717185122-a985d3407aa7.zip
GO_MODULE_FILES+=	golang.org/x/crypto/@v/v0.0.0-20190510104115-cbcb75029529.zip
GO_MODULE_FILES+=	golang.org/x/sys/@v/v0.0.0-20190412213103-97732733099d.zip
GO_MODULE_FILES+=	golang.org/x/text/@v/v0.3.0.zip
GO_MODULE_FILES+=	golang.org/x/mod/@v/v0.0.0-20190513183733-4bf6d317e70e.zip
GO_MODULE_FILES+=	howett.net/plist/@v/v0.0.0-20181124034731-591f970eefbb.zip
GO_MODULE_FILES+=	honnef.co/go/tools/@v/v0.0.0-20191107024926-a9480a3ec3bc.zip
GO_MODULE_FILES+=	github.com/kisielk/gotool/@v/v1.0.0.zip
GO_MODULE_FILES+=	github.com/google/renameio/@v/v0.1.0.zip
GO_MODULE_FILES+=	github.com/rogpeppe/go-internal/@v/v1.3.0.zip
GO_MODULE_FILES+=	github.com/!burnt!sushi/toml/@v/v0.3.1.zip
GO_MODULE_FILES+=	github.com/kr/pretty/@v/v0.1.0.zip
GO_MODULE_FILES+=	github.com/kr/text/@v/v0.1.0.zip
GO_MODULE_FILES+=	github.com/kr/pty/@v/v1.1.1.zip
GO_MODULE_FILES+=	github.com/jessevdk/go-flags/@v/v1.4.0.zip
GO_MODULE_FILES+=	gopkg.in/yaml.v2/@v/v2.2.1.zip
GO_MODULE_FILES+=	gopkg.in/check.v1/@v/v1.0.0-20180628173108-788fd7840127.zip
GO_MODULE_FILES+=	gopkg.in/errgo.v2/@v/v2.1.0.zip

post-patch:
	cd ${WRKSRC} && cp truststore_linux.go truststore_netbsd.go

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/mkcert ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"

