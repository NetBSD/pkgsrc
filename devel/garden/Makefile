# $NetBSD: Makefile,v 1.7 2024/01/28 06:47:08 pin Exp $

DISTNAME=	garden-1.2.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v1.2.0/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/garden-v1.2.0-d2d5408793d34eed1d384000b4992ce5732d5f61

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
