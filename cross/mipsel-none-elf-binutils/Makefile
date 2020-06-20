# $NetBSD: Makefile,v 1.1 2020/06/20 14:32:33 thorpej Exp $

DISTNAME=	binutils-2.32
PKGNAME=	cross-mipsel-none-elf-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	port-mips@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Cross binutils for bare metal 32-bit little-endian ELF
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # several sub-configures know --enable-nls

MIPSELELF_PREFIX=	${PREFIX}/cross-mipsel-none-elf

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${MIPSELELF_PREFIX}

CONFIGURE_ARGS+=	--disable-werror --target=mipsel-none-elf
CONFIGURE_ARGS+=	--disable-nls
INFO_FILES=		yes

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../mk/bsd.pkg.mk"
