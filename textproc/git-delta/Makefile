# $NetBSD: Makefile,v 1.4 2022/01/14 10:36:08 pin Exp $

DISTNAME=	delta-0.11.3
PKGNAME=	git-delta-0.11.3
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
