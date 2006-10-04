# $NetBSD: Makefile,v 1.21 2006/10/04 21:53:15 wiz Exp $

DISTNAME=	bing-1.0.4
CATEGORIES=	net
MASTER_SITES=	http://fgouget.free.fr/bing/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fgouget.free.fr/bing/index-en.shtml
COMMENT=	Bing is a point-to-point bandwidth measurement tool

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LDFLAGS+=	-lsocket -lnsl
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/bing
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/bing

.include "../../mk/bsd.pkg.mk"

# XXX On NetBSD the gcc-2.95.3 for:
# XXX
# XXX     alpha
# XXX
# XXX has an optimization bug when compiling with -O2 that is tickled by
# XXX ${WRKSRC}/bing.c
#
.if ${OPSYS} == "NetBSD"
.  if (${MACHINE_ARCH} == "alpha")
CXXFLAGS:=      ${CXXFLAGS:C/-O[0-9]*//g}
CFLAGS:=        ${CFLAGS:C/-O[0-9]*//g}
.  endif
.endif
