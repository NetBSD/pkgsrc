# $NetBSD: Makefile,v 1.2 2026/06/24 07:27:56 pin Exp $

DISTNAME=	sem-0.14.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Ataraxy-Labs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ataraxy-labs.github.io/sem/
COMMENT=	Semantic version control
LICENSE=	apache-2.0 OR mit

USE_TOOLS+=	pkg-config

WRKSRC=		${WRKDIR}/${DISTNAME}/crates/sem-cli

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${SSLBASE}/lib

CONFLICTS+=	parallel-[0-9]*

INSTALLATION_DIRS+=	bin

.include "cargo-crates.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
