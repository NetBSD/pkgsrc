# $NetBSD: Makefile,v 1.19 2024/09/11 19:45:05 pin Exp $

DISTNAME=	delta-0.18.2
PKGNAME=	git-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=dandavison/}
GITHUB_PROJECT=	delta

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dandavison/delta/
COMMENT=	Viewer for git and diff output
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.79.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.79.0 on amd64

INSTALLATION_DIRS+=	share/git-delta

post-install:
	${INSTALL_DATA} ${WRKSRC}/themes.gitconfig \
		${DESTDIR}${PREFIX}/share/git-delta

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
