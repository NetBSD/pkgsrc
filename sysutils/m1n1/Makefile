# $NetBSD: Makefile,v 1.1 2021/08/30 23:33:23 jmcneill Exp $

GITHUB_PROJECT=	m1n1
GITHUB_TAG=	4df78129aac4547231dbac662d28c3b67b13cc79
DISTNAME=	4df78129aac4547231dbac662d28c3b67b13cc79
PKGNAME=	${GITHUB_PROJECT}-20210828
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=AsahiLinux/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

GITHUB_SUBMODULES=	AsahiLinux artwork \
			35626c31f5c5a8a884aaff93f864795026495742 artwork

MAINTAINER=	port-arm@NetBSD.org
HOMEPAGE=	https://github.com/AsahiLinux/m1n1/
COMMENT=	Bootloader for Apple Silicon
LICENSE=	mit

WRKSRC=		${WRKDIR}/m1n1-4df78129aac4547231dbac662d28c3b67b13cc79
USE_TOOLS+=	gmake

BUILD_DEPENDS+=	cross-aarch64-none-elf-gcc-[0-9]*:../../cross/aarch64-none-elf-gcc
MAKE_FLAGS+=	ARCH=${PREFIX}/cross-aarch64-none-elf/bin/aarch64-none-elf-

INSTALLATION_DIRS=	share/m1n1

post-extract:
	# XXX why?
	mv -v ${WRKSRC}/artwork/artwork-*/* ${WRKSRC}/artwork

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/m1n1.macho ${DESTDIR}${PREFIX}/share/m1n1

.include "../../mk/bsd.pkg.mk"
