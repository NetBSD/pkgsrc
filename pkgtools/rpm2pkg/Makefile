# $NetBSD: Makefile,v 1.11 2002/08/23 05:22:56 jlam Exp $

DISTNAME=	rpm2pkg-1.2
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Convert RPM archives to NetBSD packages

CONFLICTS+=	suse-base<=6.4

USE_BUILDLINK2=	YES
NO_CHECKSUM=	YES
WRKSRC=		${WRKDIR}

RPMLIB=		${BUILDLINK_DIR}/lib/librpm.a

CFLAGS+=	-I${BUILDLINK_DIR}/include/rpm
LIBS=		${RPMLIB} -lintl -lz

do-build:
	${BUILDLINK_CC} ${FILESDIR}/rpm2pkg.c \
		${CFLAGS} ${LDFLAGS} ${LIBS} -o ${WRKSRC}/rpm2pkg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rpm2pkg ${PREFIX}/sbin
	${INSTALL_MAN} ${FILESDIR}/rpm2pkg.8 ${PREFIX}/man/man8

.include "../../devel/zlib/buildlink2.mk"
.include "../../misc/rpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
