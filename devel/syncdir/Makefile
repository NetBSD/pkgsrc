# $NetBSD: Makefile,v 1.10 2014/10/09 14:06:31 wiz Exp $
#

DISTNAME=		syncdir-1.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://untroubled.org/syncdir/
COMMENT=		Implementation of open, link, rename, and unlink

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
