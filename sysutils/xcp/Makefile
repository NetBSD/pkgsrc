# $NetBSD: Makefile,v 1.1 2022/10/04 11:25:51 pin Exp $

DISTNAME=	xcp-0.9.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=tarka/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tarka/xcp/
COMMENT=	Extended cp
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/xcp \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
