# $NetBSD: Makefile,v 1.4 2004/11/14 08:42:28 jlam Exp $
#

DISTNAME=		syncdir-1.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/syncdir/
COMMENT=		Implementation of open, link, rename, and unlink

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LIBTOOL=		# defined

INSTALLATION_DIRS=	lib

do-build:
	cd ${WRKSRC};							\
	${LIBTOOL} --mode=compile ${CC} ${CFLAGS} -c syncdir.c;	\
	${LIBTOOL} --mode=link ${CC} ${LDFLAGS} -version-info 1:0:0 -rpath ${PREFIX}/lib -o libsyncdir.la syncdir.lo

do-install:
	cd ${WRKSRC};							\
	${LIBTOOL} --mode=install ${INSTALL_LIB} -c libsyncdir.la ${PREFIX}/lib/libsyncdir.la

.include "../../mk/bsd.pkg.mk"
