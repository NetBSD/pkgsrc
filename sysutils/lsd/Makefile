# $NetBSD: Makefile,v 1.13 2023/10/24 22:11:10 wiz Exp $

DISTNAME=	lsd-1.0.0
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=lsd-rs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/lsd-rs/lsd/
COMMENT=	The next gen ls command
LICENSE=	apache-2.0

.include "cargo-depends.mk"

INSTALLATION_DIRS=	share/doc/lsd

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libgit2}/lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/lsd.md \
		${DESTDIR}${PREFIX}/share/doc/lsd

.include "../../lang/rust/cargo.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
