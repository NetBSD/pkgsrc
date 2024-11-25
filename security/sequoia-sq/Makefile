# $NetBSD: Makefile,v 1.10 2024/11/25 07:10:27 wiz Exp $

DISTNAME=	sequoia-sq-0.39.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITLAB:=sequoia-pgp/}
GITLAB_PROJECT=	sequoia-sq
GITLAB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://user-documentation-sequoia-pgp-761d1476704b33af841fb727ea0f4fb2.gitlab.io/
COMMENT=	Sequoia-PGP command line tool
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	capnproto-[0-9]*:../../devel/capnproto

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/sequoia-sq-v0.39.0-1c96be5f624ee91575da60ef3c2873d377ad5062

USE_TOOLS+=	pkg-config

MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl:Q}
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.nettle}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.clang}/lib

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/target/release/build/sequoia-sq-*/out/man-pages/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/rust/cargo.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
