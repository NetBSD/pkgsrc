# $NetBSD: Makefile,v 1.1 2025/08/06 06:35:44 pin Exp $

DISTNAME=	pingy-0.1.9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=trinhminhtriet/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/trinhminhtriet/pingy/
COMMENT=	Fast, concurrent ping tool with real-time updates & visual charts
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
