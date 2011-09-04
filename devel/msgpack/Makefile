# $NetBSD: Makefile,v 1.3 2011/09/04 02:57:11 obache Exp $
#

DISTNAME=	msgpack-0.5.7
CATEGORIES=	devel
MASTER_SITES=	http://msgpack.org/releases/cpp/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://msgpack.org/
COMMENT=	Binary-based efficient object serialization library
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

GCC_REQD=	4.1

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
CFLAGS+=	-march=i686
CXXFLAGS+=	-march=i686
.endif

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
