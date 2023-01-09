# $NetBSD: Makefile,v 1.1 2023/01/09 17:48:34 nikita Exp $

DISTNAME=	stylua-0.15.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=JohnnyMorganz/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	StyLua

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Morganz/StyLua/
COMMENT=	Opinionated Lua code formatter
LICENSE=	mpl-2.0

.include "cargo-depends.mk"

CARGO_FEATURES=		lua52,lua53,lua54,luau
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/stylua ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../lang/rust/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
