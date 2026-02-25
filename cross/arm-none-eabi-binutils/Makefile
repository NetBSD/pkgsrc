# $NetBSD: Makefile,v 1.14 2026/02/25 08:27:41 triaxx Exp $

DISTNAME=	binutils-2.45
PKGNAME=	cross-arm-none-eabi-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Cross binutils for bare metal ARM EABI
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo perl
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # several sub-configures know --enable-nls

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

post-install:
	${RM} ${DESTDIR}${ARMELF_PREFIX}/arm-none-eabi/lib/ldscripts/stamp

.include "../../mk/bsd.pkg.mk"
