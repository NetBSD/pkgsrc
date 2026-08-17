# $NetBSD: Makefile,v 1.1 2026/08/17 14:16:48 wiz Exp $

DISTNAME=	mergiraf-0.19.0
CATEGORIES=	devel
MASTER_SITES=	-https://codeberg.org/mergiraf/mergiraf/archive/v${PKGVERSION_NOREV}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://mergiraf.org/
COMMENT=	Sophisticated merge tool
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
WRKSRC=			${WRKDIR}/mergiraf

.include "cargo-depends.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
