# $NetBSD: Makefile,v 1.13 2023/01/11 09:16:11 fcambus Exp $

DISTNAME=	patchelf-0.17.2
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
GCC_REQD=	7

.include "../../mk/bsd.pkg.mk"
