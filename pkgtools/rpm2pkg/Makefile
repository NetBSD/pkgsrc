# $NetBSD: Makefile,v 1.1.1.1 2001/01/25 08:57:53 tron Exp $

DISTNAME=	rpm2pkg-1.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt

BUILD_DEPENDS+=	${RPMLIB}:../../misc/rpm

CONFLICTS+=	suse-base<=6.4

NO_CHECKSUM=	YES
WRKSRC=		${WRKDIR}

RPMLIB=		${LOCALBASE}/lib/librpm.a

# librpm.a needs libintl.a
USE_LIBINTL=	YES
.if exists(/usr/include/libintl.h)
LIBINTL=	-lintl
.else
LIBINTL=	-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -lintl
.endif

do-build:
	${CC} ${FILESDIR}/rpm2pkg.c ${CFLAGS} -I${PREFIX}/include/rpm \
	  ${RPMLIB} -lz ${LIBINTL} -o ${WRKSRC}/rpm2pkg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rpm2pkg ${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
