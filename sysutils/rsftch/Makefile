# $NetBSD: Makefile,v 1.6 2024/04/12 11:56:29 pin Exp $

DISTNAME=	rsftch-0.4.5
CATEGORIES=	sysutils
MASTER_SITES=	https://static.crates.io/crates/rsftch/
EXTRACT_SUFX=	.crate

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/charklie/rsftch/
COMMENT=	Lightning fast hardware fetch
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
