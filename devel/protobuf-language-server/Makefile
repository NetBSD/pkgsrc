# $NetBSD: Makefile,v 1.10 2025/12/02 19:25:09 bsiegert Exp $

DISTNAME=	protobuf-language-server-0.1.1
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=lasorda/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lasorda/protobuf-language-server
COMMENT=	Language server implementation for Google Protocol Buffers
LICENSE=	apache-2.0

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/protobuf-language-server ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
