# $NetBSD: Makefile,v 1.5 2025/10/07 10:44:45 pin Exp $

DISTNAME=	treegrep-1.2.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=4imothy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/4imothy/treegrep/
COMMENT=	Pattern matcher frontend or backend which displays results in a tree
LICENSE=	cc-by-v4.0

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
