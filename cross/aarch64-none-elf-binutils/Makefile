# $NetBSD: Makefile,v 1.3 2018/11/23 05:29:39 ryoon Exp $

DISTNAME=	binutils-2.31.1
PKGNAME=	cross-aarch64-none-elf-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	port-arm@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Cross binutils for bare metal AArch64 ELF
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake makeinfo
GNU_CONFIGURE=	yes

ARMELF_PREFIX=		${PREFIX}/cross-aarch64-none-elf

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${ARMELF_PREFIX}

CONFIGURE_ARGS+=	--disable-werror --target=aarch64-none-elf
CONFIGURE_ARGS+=	--disable-nls
INFO_FILES=		yes

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../mk/bsd.pkg.mk"
