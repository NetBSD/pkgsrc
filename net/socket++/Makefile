# $NetBSD: Makefile,v 1.13 2019/11/03 11:45:53 rillig Exp $

DISTNAME=		socket++-1.12.10
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://www.linuxhacker.at/linux/downloads/src/

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		https://github.com/malaterre/socketxx
COMMENT=		C++ class library for UNIX Sockets with exception handling

INFO_FILES=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_TOOLS+=		automake gmake makeinfo
TEST_DIRS=		test
TEST_TARGET=		check

pre-configure:
	cd ${WRKSRC};						\
	${LOCALBASE}/bin/libtoolize --automake;                 \
	aclocal -I .;						\
	autoheader;						\
	automake --add-missing;					\
	autoconf

.include "../../mk/bsd.pkg.mk"
