# $NetBSD: Makefile,v 1.9 2012/10/31 11:19:49 asau Exp $
#

DISTNAME=		syncdir-1.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/syncdir/
COMMENT=		Implementation of open, link, rename, and unlink

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes

INSTALLATION_DIRS=	lib

do-build:
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile ${CC} ${CFLAGS} -c syncdir.c
	cd ${WRKSRC} && ${LIBTOOL} --mode=link ${CC} ${LDFLAGS}		\
		-o libsyncdir.la syncdir.lo				\
		-version-info 1:0:0 -rpath ${PREFIX}/lib

do-install:
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_LIB}	\
		-c libsyncdir.la ${DESTDIR}${PREFIX}/lib/libsyncdir.la

.include "../../mk/bsd.pkg.mk"
