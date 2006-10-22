# $NetBSD: Makefile,v 1.20 2006/10/22 07:01:05 rillig Exp $

DISTNAME=	bfd-crunchide-1.2
CATEGORIES=	cross
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Crunchide using libbfd, used for cross-building distributions

BUILDLINK_DEPMETHOD.cross-binutils=	build

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

USE_CROSSBASE=	yes
CPPFLAGS+=	-I${PREFIX}/include
MAKE_ENV+=	LIBS=${BFD_LIBS:Q}
MAKE_ENV+=	${BSD_MAKE_ENV}

BFD_LIBS=	${PREFIX}/lib/libbfd.a ${PREFIX}/lib/libiberty.a ${PREFIX}/lib/libintl.a

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${FILESDIR}/crunchide.1 ${FILESDIR}/crunchide.c \
		${WRKSRC}

pre-install:
	@if [ ! -d ${PREFIX}/bin ]; then ${INSTALL_PROGRAM_DIR} ${PREFIX}/bin; fi

.include "../../cross/binutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
