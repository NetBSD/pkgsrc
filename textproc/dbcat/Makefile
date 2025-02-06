# $NetBSD: Makefile,v 1.4 2025/02/06 14:23:37 wiz Exp $

DISTNAME=	dbcat-0.1.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=NishantJoshi00/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NishantJoshi00/dbcat/
COMMENT=	Equivalent of cat(1) for viewing sqlite database
LICENSE=	mit

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
