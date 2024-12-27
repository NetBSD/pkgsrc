# $NetBSD: Makefile,v 1.6 2024/12/27 21:27:19 pin Exp $

DISTNAME=	0.8.5
PKGNAME=	asuka-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://git.sr.ht/~julienxx/asuka/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~julienxx/asuka/
COMMENT=	Gemini Project client written in rust with ncurses
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=		pkg-config

WRKSRC=			${WRKDIR}/asuka-${DISTNAME}

INSTALLATION_DIRS=	bin

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.ncurses}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/asuka ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
