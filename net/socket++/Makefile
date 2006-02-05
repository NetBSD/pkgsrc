# $NetBSD: Makefile,v 1.5 2006/02/05 23:10:31 joerg Exp $
#

DISTNAME=		socket++-1.12.10
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.linuxhacker.at/linux/downloads/src/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://www.linuxhacker.at/socketxx/
COMMENT=		C++ class library for UNIX Sockets with exception handling

USE_LIBTOOL=		YES
USE_TOOLS+=		automake14
AUTOCONF_REQD=          2.50
GNU_CONFIGURE=          YES
USE_TOOLS+=		gmake
TEST_DIRS=		${WRKSRC}/test
TEST_TARGET=		check

pre-configure:
		cd ${WRKSRC};						\
		${LOCALBASE}/bin/libtoolize --automake;                 \
		aclocal -I .;						\
		autoheader;						\
		automake --add-missing;					\
		autoconf

.include "../../mk/bsd.pkg.mk"
