# $NetBSD: Makefile,v 1.14 2023/11/17 16:33:35 wiz Exp $

DISTNAME=	delta-0.16.5
PKGREVISION=	2
PKGNAME=	git-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=dandavison/}
GITHUB_PROJECT=	delta

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dandavison/delta/
COMMENT=	Viewer for git and diff output
LICENSE=	mit

.include "cargo-depends.mk"

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libgit2}/lib

INSTALLATION_DIRS+=	share/git-delta

post-install:
	${INSTALL_DATA} ${WRKSRC}/themes.gitconfig ${DESTDIR}${PREFIX}/share/git-delta

.include "../../lang/rust/cargo.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
