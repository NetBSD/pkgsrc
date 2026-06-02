# $NetBSD: Makefile,v 1.10 2026/06/02 11:04:02 pin Exp $

DISTNAME=	treegrep-2.1.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=4imothy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/4imothy/treegrep/
COMMENT=	Pattern matcher frontend or backend which displays results in a tree
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
