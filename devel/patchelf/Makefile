# $NetBSD: Makefile,v 1.5 2021/01/25 10:39:22 fcambus Exp $

DISTNAME=	patchelf-0.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=NixOS/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NixOS/patchelf
COMMENT=	Modify the dynamic linker and RPATH of ELF binaries
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}.20200827.8d3a16e

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
