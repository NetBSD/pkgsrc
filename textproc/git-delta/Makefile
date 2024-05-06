# $NetBSD: Makefile,v 1.16 2024/05/06 05:41:03 pin Exp $

DISTNAME=	delta-0.17.0
PKGNAME=	git-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=dandavison/}
GITHUB_PROJECT=	delta

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dandavison/delta/
COMMENT=	Viewer for git and diff output
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS+=	share/git-delta

post-install:
	${INSTALL_DATA} ${WRKSRC}/themes.gitconfig ${DESTDIR}${PREFIX}/share/git-delta

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
