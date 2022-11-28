# $NetBSD: Makefile,v 1.1 2022/11/28 09:53:09 pin Exp $

DISTNAME=	balance-tui-0.1.0
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=BeaconBrigade/}
GITHUB_TAG=	5523e04d07c3ba14f02e1ee6c4d58117d3c06269

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/BeaconBrigade/balance-tui/
COMMENT=	Balance chemical equations from the CLI
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/cmbl \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
