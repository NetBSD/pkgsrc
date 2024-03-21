# $NetBSD: Makefile,v 1.10 2024/03/21 11:29:36 pin Exp $

DISTNAME=	garden-1.4.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v1.4.0/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/garden-v1.4.0-51d4ef97b4418edd55e2ae6f3d60be0cd4324455

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
