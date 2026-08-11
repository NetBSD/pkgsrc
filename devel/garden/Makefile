# $NetBSD: Makefile,v 1.29 2026/08/11 13:12:57 pin Exp $

DISTNAME=	garden-2.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v2.6.2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.88.0

WRKSRC=		${WRKDIR}/garden-v2.6.2-f698f999e149eef9c936e61609fbf2c3e2f16dce

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
