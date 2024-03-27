# $NetBSD: Makefile,v 1.1 2024/03/27 09:59:33 pin Exp $

DISTNAME=	rsftch-0.2.7
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
