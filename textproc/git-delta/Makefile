# $NetBSD: Makefile,v 1.15 2024/03/18 08:37:43 pin Exp $

DISTNAME=	delta-0.17.0
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
