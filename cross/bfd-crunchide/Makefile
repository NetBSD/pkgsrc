# $NetBSD: Makefile,v 1.16 2005/12/05 20:49:56 rillig Exp $

DISTNAME=	bfd-crunchide-1.1
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	sakamoto@NetBSD.org
COMMENT=	Crunchide using libbfd, used for cross-building distributions

BUILDLINK_DEPMETHOD.cross-binutils=	build

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

USE_CROSSBASE=	yes
CPPFLAGS+=	-I${PREFIX}/include
MAKE_ENV+=	LIBS=${BFD_LIBS:Q}

BFD_LIBS=	${PREFIX}/lib/libbfd.a ${PREFIX}/lib/libiberty.a ${PREFIX}/lib/libintl.a

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${FILESDIR}/crunchide.1 ${FILESDIR}/crunchide.c \
		${WRKSRC}

pre-install:
	@if [ ! -d ${PREFIX}/bin ]; then ${INSTALL_PROGRAM_DIR} ${PREFIX}/bin; fi

.include "../../cross/binutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
