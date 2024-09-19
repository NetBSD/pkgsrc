# $NetBSD: Makefile,v 1.1 2024/09/19 21:04:42 wiz Exp $

DISTNAME=	pueue-3.4.1
CATEGORIES=	sysutils
#MASTER_SITES=	${MASTER_SITE_GITHUB:=Nukesor/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=0323pin/}
GITHUB_TAG=	ddd925165d6f230c742854b43ec71f1d78acb559

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Nukesor/pueue/
COMMENT=	Manage your shell commands
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pueue \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pueued \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
