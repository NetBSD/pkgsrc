# $NetBSD: Makefile,v 1.13 2004/01/20 12:10:55 agc Exp $

DISTNAME=	bfd-crunchide-1.1
CATEGORIES=	cross
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	sakamoto@NetBSD.org
COMMENT=	crunchide using libbfd. Used for cross-building distributions

DEPENDS=	cross-binutils>=2.9.1.1:../binutils

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

USE_CROSSBASE=	yes
BFD_VERSION=	2.9.1
CPPFLAGS+=	-I${PREFIX}/include
MAKE_ENV+=	BFD_VERSION=${BFD_VERSION} \
		LIBS="${BFD_LIBS}"

FIX_RPATH+=	BFD_LIBS
BFD_LIBS=	-L${PREFIX}/lib -Wl,${RPATH_FLAG}${PREFIX}/lib -lbfd-${BFD_VERSION} -liberty

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${FILESDIR}/crunchide.1 ${FILESDIR}/crunchide.c \
		${WRKSRC}

pre-install:
	@if [ ! -d ${PREFIX}/bin ]; then ${INSTALL_PROGRAM_DIR} ${PREFIX}/bin; fi

.include "../../mk/bsd.pkg.mk"
