# $NetBSD: Makefile,v 1.4 2023/04/10 15:20:35 pin Exp $

DISTNAME=	diffr-0.1.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=mookid/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mookid/diffr/
COMMENT=	Yet another diff highlighting tool
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/diffr ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
