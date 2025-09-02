# $NetBSD: Makefile,v 1.2 2025/09/02 16:40:03 wiz Exp $

# make sure to upload a copy to ftp.NetBSD.org when updating this package
DISTNAME=	usenet_reborn-0.2.0
CATEGORIES=	news
# doesn't allow direct downloads
#MASTER_SITES=	https://git.sr.ht/~rek2/usenet_reborn/archive/

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
