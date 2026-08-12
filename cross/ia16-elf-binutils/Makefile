# $NetBSD: Makefile,v 1.1 2026/08/12 16:23:29 ryoon Exp $

DISTNAME=		binutils-ia16
PKGNAME=		ia16-elf-binutils-2.39pre20260424
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GITLAB:=tkchia/}
GITLAB_PROJECT=		binutils-ia16
GITLAB_TAG=		904e46a417122e7f2077ba6f8427b4b219b80c04

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://gitlab.com/tkchia/binutils-ia16
COMMENT=		GNU binutils for IA16 cross environment
LICENSE=		gnu-gpl-v3

WRKSRC=			${WRKDIR}/${DISTNAME}-${GITLAB_TAG}

USE_LANGUAGES+=		c c++
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/cross/ia16-elf
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
INFO_FILES=		yes

USE_GNU_CONFIGURE_TARGET=	yes
TARGET_MACHINE_GNU_PLATFORM=	ia16-elf

CONFIGURE_ARGS+=	--disable-libctf
CONFIGURE_ARGS+=	--disable-gdb
CONFIGURE_ARGS+=	--disable-libdecnumber
CONFIGURE_ARGS+=	--disable-readline
CONFIGURE_ARGS+=	--disable-sim
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--enable-ld=default
CONFIGURE_ARGS+=	--enable-gold=yes
CONFIGURE_ARGS+=	--enable-targets=ia16-elf
CONFIGURE_ARGS+=	--enable-x86-hpa-segelf=yes
CONFIGURE_ARGS+=	--disable-werror

.include "../../mk/bsd.pkg.mk"
