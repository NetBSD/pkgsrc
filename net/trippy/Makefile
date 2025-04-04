# $NetBSD: Makefile,v 1.14 2025/04/04 20:22:43 pin Exp $

DISTNAME=	trippy-0.12.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=fujiapple852/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fujiapple852/trippy/
COMMENT=	Network diagnostic tool
LICENSE=	apache-2.0

.include "cargo-depends.mk"

RUST_REQ=	1.76.0

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/trip \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
