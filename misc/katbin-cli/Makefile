# $NetBSD: Makefile,v 1.1 2022/11/24 15:26:13 pin Exp $

DISTNAME=	katbin-cli-1.3.13
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=sphericalkat/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/sphericalkat/katbin-cli/
COMMENT=	CLI for katbin
LICENSE=	mit OR apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/katbin \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
