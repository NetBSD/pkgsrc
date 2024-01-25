# $NetBSD: Makefile,v 1.9 2024/01/25 10:02:10 pin Exp $

DISTNAME=	bkt-0.8.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=dimo414/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.bkt.rs/
COMMENT=	Subprocess caching utility
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
