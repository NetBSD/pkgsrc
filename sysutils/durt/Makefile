# $NetBSD: Makefile,v 1.2 2023/01/29 20:06:21 pin Exp $

DISTNAME=	durt-1.0.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=cauebs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cauebs/durt/
COMMENT=	CLI tool for calculating the size of files and directories
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/durt ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
