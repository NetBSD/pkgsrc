# $NetBSD: Makefile,v 1.12 2003/02/08 16:26:55 dmcmahill Exp $
# FreeBSD Id: Makefile,v 1.2 1997/10/13 09:14:49 tg Exp
#

DISTNAME=	bing-1.0.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ibp.fr/pub/networking/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cnam.fr/reseau/bing.html
COMMENT=	Bing is a point-to-point bandwith measurement tool

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

