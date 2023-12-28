# $NetBSD: Makefile,v 1.5 2023/12/28 20:45:02 pin Exp $

DISTNAME=	garden-1.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v1.0.0/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/garden-v1.0.0-59adc8e15f8c1fbf00ba48ad3a88cdaa7414f2e2

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
