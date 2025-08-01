# $NetBSD: Makefile,v 1.1 2025/08/01 20:25:32 pin Exp $

DISTNAME=	sshs-4.7.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=quantumsheep/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/quantumsheep/sshs/
COMMENT=	Terminal user interface for SSH
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
