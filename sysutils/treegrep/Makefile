# $NetBSD: Makefile,v 1.3 2024/06/03 19:48:30 pin Exp $

DISTNAME=	treegrep-0.1.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=4imothy/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/4imothy/treegrep/
COMMENT=	Pattern matcher frontend or backend which displays results in a tree
LICENSE=	cc-by-v4.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
