# $NetBSD: Makefile,v 1.20 2004/01/20 12:23:58 agc Exp $

DISTNAME=	rpm2pkg-1.3
PKGREVISION=			1
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/Packages.txt
COMMENT=	Convert RPM archives to NetBSD packages

CONFLICTS+=	suse-base<=6.4

WRKSRC=		${WRKDIR}
USE_BUILDLINK2=	YES
NO_CHECKSUM=	YES

CFLAGS+=	${BUILDLINK_CPPFLAGS.rpm}
LIBS=		-lrpm -lintl -lz

do-build:
	${BUILDLINK_CC} ${CFLAGS} ${LDFLAGS} -o ${WRKSRC}/rpm2pkg \
		${FILESDIR}/rpm2pkg.c ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rpm2pkg ${PREFIX}/sbin
	${INSTALL_MAN} ${FILESDIR}/rpm2pkg.8 ${PREFIX}/man/man8

.include "../../devel/zlib/buildlink2.mk"
.include "../../misc/rpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
