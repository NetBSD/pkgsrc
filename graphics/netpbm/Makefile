# $NetBSD: Makefile,v 1.57 2001/06/19 04:22:08 jlam Exp $

DISTNAME=	netpbm-9.7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netpbm/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://netpbm.sourceforge.net/
COMMENT=	toolkit for conversion of images between different formats

USE_GMAKE=	yes
USE_LIBTOOL=	yes

INSTALL_TARGET=	install-dev install
MAKE_ENV+=	CC="${CC}" INSTALL="${INSTALL}"
MAKEFILE=	GNUmakefile

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == NetBSD) && (${MACHINE_ARCH} == arm32)
CFLAGS=
.endif

USE_BUILDLINK_ONLY=	yes

.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"

.if (${OPSYS} == SunOS)
MAKE_ENV+=	NETWORKLD="-lsocket -lnsl"
.else
MAKE_ENV+=	NETWORKLD=""
.endif

post-patch:
	${MV} -f ${WRKSRC}/pbmplus.h ${WRKSRC}/pbmplus.h.in
	${SED} -e "s;@X11BASE@;${X11BASE};g" ${WRKSRC}/pbmplus.h.in > ${WRKSRC}/pbmplus.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/shhopt/shhopt.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
