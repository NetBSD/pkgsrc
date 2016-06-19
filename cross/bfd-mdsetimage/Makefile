# $NetBSD: Makefile,v 1.26 2016/06/19 16:20:27 wiz Exp $

DISTNAME=	bfd-mdsetimage-1.15.1
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Mdsetimage using libbfd, used for cross-building distributions
LICENSE=	modified-bsd

INSTALLATION_DIRS=	cross/bin

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes

BFD_VERSION=	2.9.1
CPPFLAGS+=	-I${PREFIX}/cross/include
MAKE_ENV+=	BFD_VERSION=${BFD_VERSION:Q} \
		LIBS=${BFD_LIBS:Q}
MAKE_FLAGS+=	PREFIX=${PREFIX}/cross
MAKE_FLAGS+=	BINDIR=${PREFIX}/cross/bin

FIX_RPATH+=	BFD_LIBS
BFD_LIBS=	-L${PREFIX}/cross/lib ${COMPILER_RPATH_FLAG}${PREFIX}/cross/lib -lbfd -liberty -lintl

USE_BSD_MAKEFILE=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${FILESDIR}/mdsetimage.8 ${FILESDIR}/mdsetimage.c \
		${WRKSRC}

.include "../../cross/cross-binutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
