# $NetBSD: Makefile,v 1.26 2026/01/28 11:20:21 pin Exp $

DISTNAME=	garden-2.5.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v2.5.1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.88.0

WRKSRC=		${WRKDIR}/garden-v2.5.1-e854e8e5299d0ae24373f5921ef9863232c72e4d

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
