# $NetBSD: Makefile,v 1.11 2023/05/17 21:38:23 wiz Exp $

DISTNAME=	delta-0.15.1
PKGNAME=	git-delta-0.15.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=dandavison/}
GITHUB_PROJECT=	delta

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dandavison/delta/
COMMENT=	Viewer for git and diff output
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
