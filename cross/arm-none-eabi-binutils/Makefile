# $NetBSD: Makefile,v 1.10 2020/03/17 21:33:24 rillig Exp $

DISTNAME=	binutils-2.32
PKGNAME=	cross-arm-none-eabi-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Cross binutils for bare metal ARM EABI
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # several sub-configures don't know --enable-nls

ARMELF_PREFIX=		${PREFIX}/cross-arm-none-eabi

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${ARMELF_PREFIX}

CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--target=arm-none-eabi
CONFIGURE_ARGS+=	--disable-nls
INFO_FILES=		yes

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../mk/bsd.pkg.mk"
