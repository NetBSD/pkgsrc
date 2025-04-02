# $NetBSD: Makefile,v 1.3 2025/04/02 11:11:05 pin Exp $

DISTNAME=	pueue-3.4.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=Nukesor/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	7beda35b14d0b45e24669c0bd94a4f967aa1d54d

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Nukesor/pueue/
COMMENT=	Manage your shell commands
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
NOT_FOR_PLATFORM+=	*-*-i386

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pueue \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/pueued \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
