# $NetBSD: Makefile,v 1.16 2023/04/30 10:48:23 fcambus Exp $

DISTNAME=	patchelf-0.18.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=NixOS/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/NixOS/patchelf
COMMENT=	Modify the dynamic linker and RPATH of ELF binaries
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++17
# std::optional
GCC_REQD+=	8

.include "../../mk/bsd.pkg.mk"
