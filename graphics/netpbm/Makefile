# $NetBSD: Makefile,v 1.62 2002/05/14 18:03:17 tron Exp $

DISTNAME=	netpbm-9.25
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netpbm/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://netpbm.sourceforge.net/
COMMENT=	toolkit for conversion of images between different formats

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
USE_PERL5=		yes

REPLACE_PERL=		pnm/pnmquant ppm/ppmfade ppm/ppmrainbow ppm/ppmshadow

INSTALL_TARGET=	install-dev install
MAKE_ENV+=	CC="${CC}" INSTALL="${INSTALL}" STRIPFLAG="${STRIPFLAG}"
MAKEFILE=	GNUmakefile

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == NetBSD) && (${MACHINE_ARCH} == arm32)
CFLAGS=
.endif

.if (${OPSYS} == SunOS)
MAKE_ENV+=	NETWORKLD="-lsocket -lnsl"
.else
MAKE_ENV+=	NETWORKLD=""
.endif

post-patch:
	${CP} ${WRKSRC}/Makefile.config.in ${WRKSRC}/Makefile.config

post-install:
	${INSTALL_DATA} ${WRKSRC}/shhopt/shhopt.h ${PREFIX}/include

.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
