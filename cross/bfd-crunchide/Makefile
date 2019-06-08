# $NetBSD: Makefile,v 1.28 2019/06/08 10:53:27 rillig Exp $

DISTNAME=	bfd-crunchide-1.2
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Crunchide using libbfd, used for cross-building distributions

BUILDLINK_DEPMETHOD.cross-binutils=	build

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes

CPPFLAGS+=		-I${PREFIX}/cross/include
MAKE_ENV+=		LIBS=${BFD_LIBS:Q}
MAKE_ENV+=		${BSD_MAKE_ENV}
USE_BSD_MAKEFILE=	yes
MAKE_FLAGS+=		PREFIX=${PREFIX}/cross
MAKE_FLAGS+=		BINDIR=${PREFIX}/cross/bin

BFD_LIBS=	${PREFIX}/cross/lib/libbfd.a ${PREFIX}/cross/lib/libiberty.a ${PREFIX}/cross/lib/libintl.a

INSTALLATION_DIRS=	cross/bin

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${FILESDIR}/crunchide.1 ${FILESDIR}/crunchide.c \
		${WRKSRC}

.include "../../cross/cross-binutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
