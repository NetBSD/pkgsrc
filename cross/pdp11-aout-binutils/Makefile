# $NetBSD: Makefile,v 1.1 2017/07/03 17:28:39 ryoon Exp $

DISTNAME=	binutils-2.28
PKGNAME=	cross-pdp11-aout-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Cross binutils for PDP-11 a.out
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake makeinfo
GNU_CONFIGURE=	yes

PDP11AOUT_PREFIX=		${PREFIX}/cross-pdp11-aout

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${PDP11AOUT_PREFIX}

CONFIGURE_ARGS+=	--target=pdp11-aout
CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--disable-nls
INFO_FILES=		yes

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../mk/bsd.pkg.mk"
