# $NetBSD: Makefile,v 1.1.1.1 1999/12/20 05:58:34 sakamoto Exp $

DISTNAME=	bfd-mdsetimage-1.0
CATEGORIES=	cross
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	sakamoto@netbsd.org

DEPENDS=	cross-binutils-2.9.1.1:../binutils

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
	@${CP} ${FILESDIR}/* ${WRKSRC}

pre-install:
	@if [ ! -d ${PREFIX}/bin ];then ${MKDIR} ${PREFIX}/bin;fi

.include "../../mk/bsd.pkg.mk"
