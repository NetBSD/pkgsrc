# $NetBSD: Makefile,v 1.23 2004/04/25 11:50:39 wiz Exp $

DISTNAME=	rpm2pkg-2.0
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.netbsd.org/Documentation/pkgsrc/
COMMENT=	Convert RPM archives to NetBSD packages

CONFLICTS+=	suse-base<=6.4

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=	YES
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

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../misc/rpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
