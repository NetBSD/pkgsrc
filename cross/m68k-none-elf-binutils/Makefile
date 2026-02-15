# $NetBSD: Makefile,v 1.1 2026/02/15 23:22:03 mrg Exp $

DISTNAME=	binutils-2.46.0
PKGNAME=	cross-m68k-none-elf-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	port-m68k@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Cross binutils for bare metal m68k ELF
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # several sub-configures know --enable-nls

POWERPCELF_PREFIX=	${PREFIX}/cross-m68k-none-elf

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${POWERPCELF_PREFIX}

CONFIGURE_ARGS+=	--disable-werror --target=m68k-none-elf
CONFIGURE_ARGS+=	--disable-nls
INFO_FILES=		yes

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../mk/bsd.pkg.mk"
