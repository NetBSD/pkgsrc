# $NetBSD: Makefile,v 1.7 2025/10/27 12:06:53 pin Exp $

DISTNAME=	treegrep-1.3.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=4imothy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/4imothy/treegrep/
COMMENT=	Pattern matcher frontend or backend which displays results in a tree
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
