# $NetBSD: Makefile,v 1.1 2024/04/02 22:33:56 js Exp $

DISTNAME=	binutils-2.42
PKGNAME=	libdragon-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Cross binutils for libdragon
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # several sub-configures know --enable-nls

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${PREFIX}/libdragon

CONFIGURE_ARGS+=	--target=mips64-elf
CONFIGURE_ARGS+=	--with-cpu=mips64vr4300
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-werror

USE_LANGUAGES=		c c++
USE_TOOLS+=		perl

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../mk/bsd.pkg.mk"
