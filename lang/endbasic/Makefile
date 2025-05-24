# $NetBSD: Makefile,v 1.1 2025/05/24 00:57:33 schmonz Exp $

DISTNAME=		endbasic-0.11.1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GITHUB:=endbasic/}
GITHUB_PROJECT=		endbasic
GITHUB_TAG=		${DISTNAME}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.endbasic.dev/
COMMENT=		BASIC interpreter + DOS environment, reimagined
LICENSE=		apache-2.0

.include "cargo-depends.mk"

USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config

AUTO_MKDIRS=		yes

RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${SSLBASE}/lib
RUSTFLAGS+=		-C link-arg=${COMPILER_RPATH_FLAG}${PREFIX}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/${PKGBASE} ${DESTDIR}${PREFIX}/bin/

.include "../../lang/rust/cargo.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
