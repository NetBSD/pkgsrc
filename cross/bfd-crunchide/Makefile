# $NetBSD: Makefile,v 1.4 2001/02/16 14:04:54 wiz Exp $

DISTNAME=	bfd-crunchide-1.0
CATEGORIES=	cross
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	sakamoto@netbsd.org
COMMENT=	crunchide using libbfd. Used for cross-building distributions

DEPENDS=	cross-binutils>=2.9.1.1:../binutils

EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_CONFIGURE=	yes

USE_CROSSBASE=	yes
BFD_VERSION=	2.9.1
MAKE_ENV+=	BFD_VERSION=${BFD_VERSION} \
		CPPFLAGS="-I${PREFIX}/include" \
		LIBS="-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lbfd-${BFD_VERSION} -liberty"

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${FILESDIR}/crunchide.1 ${FILESDIR}/crunchide.c \
		${WRKSRC}

pre-install:
	@if [ ! -d ${PREFIX}/bin ]; then ${MKDIR} ${PREFIX}/bin; fi

.include "../../mk/bsd.pkg.mk"
