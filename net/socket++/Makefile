# $NetBSD: Makefile,v 1.9 2010/01/16 17:48:02 wiz Exp $
#

DISTNAME=		socket++-1.12.10
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://www.linuxhacker.at/linux/downloads/src/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://www.linuxhacker.at/socketxx/
COMMENT=		C++ class library for UNIX Sockets with exception handling

PKG_DESTDIR_SUPPORT=	user-destdir

INFO_FILES=		# PLIST
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
USE_TOOLS+=		automake
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake makeinfo
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
