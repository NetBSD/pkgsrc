# $NetBSD: Makefile,v 1.1 2026/08/12 16:28:25 ryoon Exp $

DISTNAME=		libi86
PKGNAME=		ia16-elf-libi86-0.0.${GITLAB_TAG}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GITLAB:=tkchia/}
GITLAB_PROJECT=		libi86
GITLAB_TAG=		521a43f42a3daf00b85b62c44390821f532def8f

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://gitlab.com/tkchia/libi86
COMMENT=		libi86 for IA16 cross environment
LICENSE=		modified-bsd

TOOL_DEPENDS+=		ia16-elf-binutils-[0-9]*:../../cross/ia16-elf-binutils
BUILD_DEPENDS+=		ia16-elf-newlib-bootstrap-[0-9]*:../../cross/ia16-elf-newlib-bootstrap
TOOL_DEPENDS+=		ia16-elf-gcc-bootstrap-[0-9]*:../../cross/ia16-elf-gcc-bootstrap

WRKSRC=			${WRKDIR}/${DISTNAME}-${GITLAB_TAG}

USE_LANGUAGES+=		c c++
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf gmake gsed

TARGET_MACHINE_GNU_PLATFORM=	ia16-elf

USE_GNU_CONFIGURE_HOST=	no
GNU_CONFIGURE_STRICT=	no # has sub-configures
CONFIGURE_DIRS=		host-gcc
GNU_CONFIGURE_PREFIX=	${PREFIX}/cross/ia16-elf

CONFIGURE_ARGS+=	--host=ia16-elf
#CONFIGURE_ARGS+=	--with-build-time-tools=${PREFIX}/cross/ia16-elf/bin

CONFIGURE_ENV+=		ac_cv_prog_CC=${PREFIX}/cross/ia16-elf-bootstrap/bin/ia16-elf-gcc

.include "../../mk/bsd.pkg.mk"
