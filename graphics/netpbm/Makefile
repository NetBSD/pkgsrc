# $NetBSD: Makefile,v 1.44 2000/06/24 01:48:08 dmcmahill Exp $

DISTNAME=	netpbm-9.3
CATEGORIES=	graphics
MASTER_SITES=	http://download.sourceforge.net/netpbm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://netpbm.sourceforge.net/info

DEPENDS+=	tiff>=3.5.4:../../graphics/tiff
DEPENDS+=	png>=1.0.6:../../graphics/png

USE_GMAKE=	yes
USE_LIBTOOL=	yes

INSTALL_TARGET=	install-dev install
MAKEFILE=	GNUmakefile

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == NetBSD && ${MACHINE_ARCH} == arm32
CFLAGS=
.endif

post-patch:
	${MV} -f ${WRKSRC}/pbmplus.h ${WRKSRC}/pbmplus.h.in
	${SED} -e "s;@X11BASE@;${X11BASE};g" ${WRKSRC}/pbmplus.h.in > ${WRKSRC}/pbmplus.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/shhopt/shhopt.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
