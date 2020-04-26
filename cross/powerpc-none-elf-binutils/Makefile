# $NetBSD: Makefile,v 1.2 2020/04/26 09:47:40 rillig Exp $

DISTNAME=	binutils-2.32
PKGNAME=	cross-powerpc-none-elf-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	port-powerpc@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Cross binutils for bare metal PowerPC ELF
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # several sub-configures know --enable-nls

POWERPCELF_PREFIX=	${PREFIX}/cross-powerpc-none-elf

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${POWERPCELF_PREFIX}

CONFIGURE_ARGS+=	--disable-werror --target=powerpc-none-elf
CONFIGURE_ARGS+=	--disable-nls
INFO_FILES=		yes

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../mk/bsd.pkg.mk"
