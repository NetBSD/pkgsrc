# $NetBSD: Makefile,v 1.28 2026/07/14 10:58:28 pin Exp $

DISTNAME=	garden-2.6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v2.6.1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.88.0

WRKSRC=		${WRKDIR}/garden-v2.6.1-50a2dbfdb623b88f24fa3bcd392ea93b7a661cfc

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
