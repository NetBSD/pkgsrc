# $NetBSD: Makefile,v 1.9 2025/04/10 19:35:22 pin Exp $

DISTNAME=	angle-grinder-0.19.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=rcoh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rcoh/angle-grinder/
COMMENT=	Slice and dice logs on the command line
LICENSE=	mit

.include "cargo-depends.mk"

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake pkg-config

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
