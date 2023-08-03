# $NetBSD: Makefile,v 1.1 2023/08/03 18:25:05 pin Exp $

DISTNAME=	lla-0.1.3
CATEGORIES=	sysutils
MASTER_SITES=	https://static.crates.io/crates/lla/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/triyanox/lla/
COMMENT=	The Elegant ls Alternative
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
