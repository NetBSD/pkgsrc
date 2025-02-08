# $NetBSD: Makefile,v 1.3 2025/02/08 18:22:24 schmonz Exp $

DISTNAME=	codeberg-cli-0.4.7
CATEGORIES=	devel
MASTER_SITES=	${HOMEPAGE}archive/
SITES.${DISTNAME}.tar.gz=	-${MASTER_SITES}v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://codeberg.org/Aviac/codeberg-cli/
COMMENT=	CLI for codeberg and forgejo similar to gh, glab and tea
LICENSE=	gnu-agpl-v3

WRKSRC=		${WRKDIR}/${PKGBASE}

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${SSLBASE}/lib

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
