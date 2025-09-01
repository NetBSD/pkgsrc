# $NetBSD: Makefile,v 1.1 2025/09/01 18:42:22 vins Exp $

DISTNAME=	0.2.0
PKGNAME=	${DISTNAME:S|^|usenet_reborn-|}
CATEGORIES=	news
MASTER_SITES=	https://git.sr.ht/~rek2/usenet_reborn/archive/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~rek2/usenet_reborn/
COMMENT=	TUI client for Usenet enthusiasts
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

MAKE_ENV+=	OPENSSL_DIR=${SSLBASE:Q}

RUSTFLAGS+=	-C link-arg=-L${SSLBASE}/lib 				\
		-C link-arg=${COMPILER_RPATH_FLAG}${SSLBASE}/lib	\
		-C link-arg=-L${SSLBASE}/lib				\
		-C link-arg=-L${BUILDLINK_PREFIX.sqlite3}/lib		\
		-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib

.include "cargo-depends.mk"

EGDIR=		share/examples/${PKGBASE}
EGFILES=	config.toml subscriptions

INSTALLATION_DIRS+=	${EGDIR}

WRKSRC=		${WRKDIR}/${PKGBASE}-${PKGVERSION_NOREV}

post-install:
	${INSTALL_DATA} ${EGFILES:S|^|${WRKSRC}/configs/|}	\
		${DESTDIR}${PREFIX}/${EGDIR}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
