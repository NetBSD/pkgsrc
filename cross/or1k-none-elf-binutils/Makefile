# $NetBSD: Makefile,v 1.1 2019/07/15 05:59:13 maya Exp $

DISTNAME=	binutils-2.32
PKGNAME=	cross-or1k-none-elf-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceware.org/binutils/
COMMENT=	Cross binutils for bare metal OpenRISC 1000 ELF
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake makeinfo
GNU_CONFIGURE=	yes

ORELF_PREFIX=		${PREFIX}/cross-or1k-none-elf

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${ORELF_PREFIX}

CONFIGURE_ARGS+=	--disable-werror --target=or1k-none-elf
CONFIGURE_ARGS+=	--disable-nls
INFO_FILES=		yes

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../mk/bsd.pkg.mk"
