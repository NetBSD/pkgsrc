# $NetBSD: Makefile,v 1.18 2024/10/14 18:38:20 gdt Exp $

DISTNAME=	patchelf-0.18.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=NixOS/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NixOS/patchelf
COMMENT=	Modify the dynamic linker and RPATH of ELF binaries
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_CXX_FEATURES=	c++17
# This package use std::optional.  std::optional is part of c++17, and
# is not split out in mk/compiler/gcc.mk.  Thus, declaring c++17
# results in a gcc7 requirement.  Work around this mk/ bug by
# requiring a higher version.  Choose 10 to align with the
# limited-versions guidance.
GCC_REQD+=	10

.include "../../mk/bsd.pkg.mk"
