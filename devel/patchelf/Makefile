# $NetBSD: Makefile,v 1.7 2021/12/29 11:52:24 rhialto Exp $

DISTNAME=	patchelf-0.14.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=NixOS/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NixOS/patchelf
COMMENT=	Modify the dynamic linker and RPATH of ELF binaries
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++17

.include "../../mk/bsd.pkg.mk"
