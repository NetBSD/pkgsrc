# $NetBSD: Makefile,v 1.11 2024/03/23 19:09:39 pin Exp $

DISTNAME=	garden-1.4.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITLAB:=garden-rs/garden/-/archive/v1.4.1/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://garden-rs.gitlab.io/
COMMENT=	Grows and cultivates collections of Git trees
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/garden-v1.4.1-efbd9230135bd3b4a23b9e2decc449d74992bd5d

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
