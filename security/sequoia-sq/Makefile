# $NetBSD: Makefile,v 1.2 2024/02/28 19:19:15 pin Exp $

DISTNAME=	sequoia-sq-0.33.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITLAB:=sequoia-pgp/}
GITLAB_PROJECT=	sequoia-sq
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sequoia-pgp.gitlab.io/sq-user-guide/
COMMENT=	Sequoia-PGP command line tool
LICENSE=	gnu-gpl-v2

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/sequoia-sq-v0.33.0-195ef2bf9b218ff4d6f25b1854f9f4558f449672

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.nettle}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.clang}/lib

.include "../../lang/rust/cargo.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
