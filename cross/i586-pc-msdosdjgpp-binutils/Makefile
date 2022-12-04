# $NetBSD: Makefile,v 1.2 2022/12/04 21:13:31 js Exp $

DISTNAME=	binutils-2.39
PKGNAME=	cross-i586-pc-msdosdjgpp-${DISTNAME}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=binutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	js@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Cross binutils for DJGPP
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo perl
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # several sub-configures know --enable-nls

DJGPP_PREFIX=		${PREFIX}/cross-djgpp

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
GNU_CONFIGURE_PREFIX=	${DJGPP_PREFIX}

CONFIGURE_ARGS+=	--disable-werror
CONFIGURE_ARGS+=	--target=i586-pc-msdosdjgpp
CONFIGURE_ARGS+=	--disable-nls
INFO_FILES=		yes

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

.include "../../mk/bsd.pkg.mk"
