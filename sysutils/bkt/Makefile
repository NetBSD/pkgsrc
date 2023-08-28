# $NetBSD: Makefile,v 1.7 2023/08/28 08:18:51 pin Exp $

DISTNAME=	bkt-0.7.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=dimo414/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dimo414/bkt/
COMMENT=	Subprocess caching utility
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
