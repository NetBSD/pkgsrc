# $NetBSD: Makefile,v 1.2 2022/12/03 17:13:45 pin Exp $

DISTNAME=	balance-tui-0.1.1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=BeaconBrigade/}
GITHUB_TAG=	5bf59733fd350ac67d8ef988d1dcfe2d0796d51b

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
