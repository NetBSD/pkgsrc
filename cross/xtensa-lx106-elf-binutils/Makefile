# $NetBSD: Makefile,v 1.2 2020/04/17 00:18:51 joerg Exp $

DISTNAME=	binutils-gdb-xtensa-2.31_20190405
PKGNAME=	${DISTNAME:C/binutils-gdb-xtensa/xtensa-lx106-elf-binutils/}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=jcmvbkbc/}
GITHUB_PROJECT=	binutils-gdb-xtensa
GITHUB_TAG=	c0b4cd465573f1772927cb3ad5d6e7d17af21622

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://github.com/espressif/binutils-gdb
COMMENT=	Cross binutils for Espressif ESP8266 bare metal environment
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

INFO_FILES=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake makeinfo perl

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${PREFIX}/xtensa-lx106-elf

CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--target=xtensa-lx106-elf
CONFIGURE_ARGS+=	--enable-multilib
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-gdb

# Running tests needs a lot more work anyway
CHECK_PORTABILITY_SKIP+=	gdb/testsuite/Makefile.in

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}
	${CP} ${FILESDIR}/xtensa-config.h ${WRKSRC}/include/xtensa-config.h

.include "../../mk/bsd.pkg.mk"
