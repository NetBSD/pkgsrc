# $NetBSD: Makefile,v 1.6 2025/04/10 13:22:25 pin Exp $

DISTNAME=	katbin-cli-1.3.15
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=sphericalkat/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
