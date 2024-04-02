# $NetBSD: Makefile,v 1.3 2024/04/02 19:39:56 pin Exp $

DISTNAME=	rsftch-0.3.7
CATEGORIES=	sysutils
MASTER_SITES=	https://static.crates.io/crates/rsftch/
EXTRACT_SUFX=	.crate

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/charklie/rsftch/
COMMENT=	Lightning fast hardware fetch
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
