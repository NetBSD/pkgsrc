# $NetBSD: Makefile,v 1.22 2004/02/18 21:29:37 tron Exp $

DISTNAME=	rpm2pkg-2.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.netbsd.org/Documentation/pkgsrc/
COMMENT=	Convert RPM archives to NetBSD packages

CONFLICTS+=	suse-base<=6.4

WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	YES
NO_CHECKSUM=	YES

CPPFLAGS+=	${BUILDLINK_CPPFLAGS.bzip2} ${BUILDLINK_CPPFLAGS.rpm} \
		${BUILDLINK_CPPFLAGS.zlib}
LIBS=		-lrpm -lintl -lz -lbz2

.include "../../mk/bsd.prefs.mk"

.if (${CC} == gcc)
CFLAGS+=	-Wall
.endif

do-build:
	${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} -o ${WRKSRC}/rpm2pkg \
		${FILESDIR}/rpm2pkg.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rpm2pkg ${PREFIX}/sbin
	${INSTALL_MAN} ${FILESDIR}/rpm2pkg.8 ${PREFIX}/man/man8

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../misc/rpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
