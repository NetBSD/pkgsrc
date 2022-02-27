# $NetBSD: Makefile,v 1.5 2022/02/27 13:41:00 fcambus Exp $

DISTNAME=	delta-0.12.0
PKGNAME=	git-delta-0.12.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=dandavison/}
GITHUB_PROJECT=	delta

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dandavison/delta/
COMMENT=	Viewer for git and diff output
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/delta ${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
