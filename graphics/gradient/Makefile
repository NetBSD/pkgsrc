# $NetBSD: Makefile,v 1.1 2022/10/15 07:13:37 pin Exp $

DISTNAME=	gradient-rs-0.3.3
PKGNAME=	gradient-0.3.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=mazznoer/}
GITHUB_PROJECT=	gradient-rs
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mazznoer/gradient-rs/
COMMENT=	CLI tool for playing with color gradients
LICENSE=	apache-2.0 AND mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/gradient \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
