# $NetBSD: Makefile,v 1.5 2021/03/30 20:29:04 pin Exp $

DISTNAME=	nanogrep-2.2.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Uniminin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://crates.io/crates/nanogrep/
COMMENT=	Custom simplified implementation of minigrep with additional features
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=		c # rust, but needs a toolchain to link

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/ng ${DESTDIR}${PREFIX}/bin/nanogrep

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
