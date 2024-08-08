# $NetBSD: Makefile,v 1.1 2024/08/08 10:41:11 wiz Exp $

DISTNAME=	mktool-0.1.8
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=jperkin/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jperkin/mktool/
COMMENT=	pkgsrc mk helper tool
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	c

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
