# $NetBSD: Makefile,v 1.17 2024/06/01 14:02:59 bsiegert Exp $

DISTNAME=	cfssl-1.6.5
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=cloudflare/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://cfssl.org/
COMMENT=	CloudFlare PKI toolkit
LICENSE=	mit

EXTRACT_USING=	bsdtar

.include "go-modules.mk"

CHECK_RELRO_SKIP+=	bin/cfssl
CHECK_RELRO_SKIP+=	bin/cfssl-bundle
CHECK_RELRO_SKIP+=	bin/cfssl-certinfo
CHECK_RELRO_SKIP+=	bin/cfssl-newkey
CHECK_RELRO_SKIP+=	bin/cfssl-scan
CHECK_RELRO_SKIP+=	bin/cfssljson
CHECK_RELRO_SKIP+=	bin/mkbundle
CHECK_RELRO_SKIP+=	bin/multirootca

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/cfssl share/doc/cfssl/api share/doc/cfssl/cmd

GO_XFLAG_PREFIX=	-X github.com/cloudflare/cfssl/cli/version
GO_LDFLAGS+=		${GO_XFLAG_PREFIX}.version=${PKGVERSION_NOREV}

do-build:
	${RUN}${_ULIMIT_CMD} cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} \
		${GO} install -v -ldflags ${GO_LDFLAGS:Q} ./cmd/...

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/* ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/cfssl
	${INSTALL_DATA} ${WRKSRC}/doc/*.sample ${DESTDIR}${PREFIX}/share/doc/cfssl
	${INSTALL_DATA} ${WRKSRC}/doc/api/*.txt ${DESTDIR}${PREFIX}/share/doc/cfssl/api
	${INSTALL_DATA} ${WRKSRC}/doc/cmd/*.txt ${DESTDIR}${PREFIX}/share/doc/cfssl/cmd

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
