# $NetBSD: Makefile,v 1.23 2009/04/09 00:48:07 joerg Exp $

DISTNAME=	bfd-mdsetimage-1.15.1
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Mdsetimage using libbfd, used for cross-building distributions

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes

USE_CROSSBASE=	yes
BFD_VERSION=	2.9.1
CPPFLAGS+=	-I${PREFIX}/include
MAKE_ENV+=	BFD_VERSION=${BFD_VERSION:Q} \
		LIBS=${BFD_LIBS:Q}

FIX_RPATH+=	BFD_LIBS
BFD_LIBS=	-L${PREFIX}/lib ${COMPILER_RPATH_FLAG}${PREFIX}/lib -lbfd -liberty -lintl

USE_BSD_MAKEFILE=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${FILESDIR}/mdsetimage.8 ${FILESDIR}/mdsetimage.c \
		${WRKSRC}

.include "../../cross/binutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
