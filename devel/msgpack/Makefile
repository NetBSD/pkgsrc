# $NetBSD: Makefile,v 1.6 2014/02/19 09:44:56 jperkin Exp $
#

DISTNAME=	msgpack-0.5.8
CATEGORIES=	devel
MASTER_SITES=	https://github.com/msgpack/msgpack-c/releases/download/cpp-${PKGVERSION_NOREV}/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://msgpack.org/
COMMENT=	Binary-based efficient object serialization library
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	msgpack.pc.in

GCC_REQD+=	4.1

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
CFLAGS+=	-march=i686
CXXFLAGS+=	-march=i686
.endif

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
