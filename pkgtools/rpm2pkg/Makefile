# $NetBSD: Makefile,v 1.8 2001/06/18 21:32:24 jlam Exp $

DISTNAME=	rpm2pkg-1.2
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	ftp://ftp.netbsd.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Convert RPM archives to NetBSD packages

CONFLICTS+=	suse-base<=6.4

NO_CHECKSUM=	YES
WRKSRC=		${WRKDIR}

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/zlib/buildlink.mk"
.include "../../misc/rpm/buildlink.mk"

USE_BUILDLINK_ONLY=	YES
#USE_LIBINTL=		YES

RPMLIB=		${BUILDLINK_DIR}/lib/librpm.a

CFLAGS+=	-I${BUILDLINK_DIR}/include/rpm
LIBS=		${RPMLIB} -lintl -lz

do-build:
	${CC} ${FILESDIR}/rpm2pkg.c ${CFLAGS} ${LDFLAGS} ${LIBS}	\
		-o ${WRKSRC}/rpm2pkg

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rpm2pkg ${PREFIX}/sbin
	${INSTALL_MAN} ${FILESDIR}/rpm2pkg.8 ${PREFIX}/man/man8

.include "../../mk/bsd.pkg.mk"
