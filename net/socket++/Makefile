# $NetBSD: Makefile,v 1.1.1.1 2005/03/27 17:45:38 wiz Exp $
#

DISTNAME=		socket++-1.12.10
CATEGORIES=		net
MASTER_SITES=		http://www.linuxhacker.at/linux/downloads/src/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://www.linuxhacker.at/socketxx/
COMMENT=		C++ class library for UNIX Sockets with exception handling

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
AUTOMAKE_REQD=          1.4
AUTOCONF_REQD=          2.50
GNU_CONFIGURE=          YES
USE_GNU_TOOLS+=		make
TEST_DIRS=		${WRKSRC}/test
TEST_TARGET=		check

pre-configure:
		cd ${WRKSRC};						\
		${LOCALBASE}/bin/libtoolize --automake;                 \
		${ACLOCAL} -I .;                                        \
		${AUTOHEADER};                                          \
		${AUTOMAKE} --add-missing;                              \
		${AUTOCONF};                                            \

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
