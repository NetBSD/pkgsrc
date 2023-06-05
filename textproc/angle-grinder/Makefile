# $NetBSD: Makefile,v 1.6 2023/06/05 15:19:57 pin Exp $

DISTNAME=	angle-grinder-0.19.2
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
