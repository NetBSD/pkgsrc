# $NetBSD: Makefile,v 1.2 2024/09/22 13:29:38 pin Exp $

DISTNAME=	pueue-3.4.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Nukesor/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	7beda35b14d0b45e24669c0bd94a4f967aa1d54d

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
