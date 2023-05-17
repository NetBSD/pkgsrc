# $NetBSD: Makefile,v 1.9 2023/05/17 21:25:59 wiz Exp $

DISTNAME=	bk-0.5.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=aeosynth/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aeosynth/bk/
COMMENT=	Terminal Epub reader
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
