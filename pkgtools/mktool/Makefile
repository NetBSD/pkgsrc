# $NetBSD: Makefile,v 1.7 2024/09/01 15:57:11 pin Exp $

DISTNAME=	mktool-0.1.20
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=jperkin/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jperkin/mktool/
COMMENT=	pkgsrc mk helper tool
LICENSE=	isc

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
