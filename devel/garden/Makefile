# $NetBSD: Makefile,v 1.27 2026/06/05 10:12:16 pin Exp $

DISTNAME=	garden-2.6.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v2.6.0/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.88.0

WRKSRC=		${WRKDIR}/garden-v2.6.0-40be5546c323b211bffb0cdda16b5e396484a385

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
