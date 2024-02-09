# $NetBSD: Makefile,v 1.8 2024/02/09 13:53:45 pin Exp $

DISTNAME=	garden-1.2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v1.2.1/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/garden-v1.2.1-e075aa78851b5e3eb388b6d510aa65a260de3d6d

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
