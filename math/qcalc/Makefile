# $NetBSD: Makefile,v 1.7 2024/06/01 14:16:08 pin Exp $

DISTNAME=	qcalc-0.9.5
CATEGORIES=	math
MASTER_SITES=	https://static.crates.io/crates/qcalc/
EXTRACT_SUFX=	.crate

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/OchirErkhembayar/qcalc/
COMMENT=	Terminal GUI calculator
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
