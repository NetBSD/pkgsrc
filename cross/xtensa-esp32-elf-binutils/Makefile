# $NetBSD: Makefile,v 1.2 2019/05/27 17:31:14 tnn Exp $

DISTNAME=	binutils-2.32
PKGREVISION=	1
PKGNAME=	${DISTNAME:C/.*binutils(-gdb)?/xtensa-esp32-elf-binutils/}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.xz
# Espressif overlays
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	crosstool-ng-esp32-2019r1.tar.gz
SITES.crosstool-ng-esp32-2019r1.tar.gz=	-https://github.com/espressif/crosstool-NG/archive/ce035ad3351127e4fdb3ff96790caba42b9f1aa3.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/espressif/binutils-gdb
COMMENT=	Cross binutils for Espressif ESP32 bare metal environment
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

INFO_FILES=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake makeinfo

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${PREFIX}/xtensa-esp32-elf

CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--target=xtensa-esp32-elf
CONFIGURE_ARGS+=	--enable-multilib
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-gdb

post-extract:
	${CP} -r ${WRKDIR}/crosstool-NG*/overlays/xtensa_esp32/binutils/. \
	    ${WRKSRC}/.

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../mk/bsd.pkg.mk"
