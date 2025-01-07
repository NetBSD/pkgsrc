# $NetBSD: Makefile,v 1.10 2025/01/07 13:35:55 tnn Exp $

DISTNAME=	binwalk-3.1.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=ReFirmLabs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ReFirmLabs/binwalk/
COMMENT=	Firmware analysis tool
LICENSE=	mit

USE_TOOLS+=	pkg-config

.include "cargo-depends.mk"

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
