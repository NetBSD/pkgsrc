# $NetBSD: Makefile,v 1.3 2024/08/19 19:15:36 wiz Exp $

DISTNAME=	mktool-0.1.11
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=jperkin/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jperkin/mktool/
COMMENT=	pkgsrc mk helper tool
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
