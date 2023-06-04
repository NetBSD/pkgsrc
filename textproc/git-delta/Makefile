# $NetBSD: Makefile,v 1.12 2023/06/04 20:18:34 pin Exp $

DISTNAME=	delta-0.16.5
PKGNAME=	git-delta-0.16.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=dandavison/}
GITHUB_PROJECT=	delta

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dandavison/delta/
COMMENT=	Viewer for git and diff output
LICENSE=	mit

.include "cargo-depends.mk"

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libgit2}/lib

.include "../../lang/rust/cargo.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
