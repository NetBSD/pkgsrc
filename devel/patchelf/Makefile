# $NetBSD: Makefile,v 1.6 2021/08/10 11:31:34 rhialto Exp $

DISTNAME=	patchelf-0.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=NixOS/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/NixOS/patchelf
COMMENT=	Modify the dynamic linker and RPATH of ELF binaries
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}.20210805.a949ff2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
