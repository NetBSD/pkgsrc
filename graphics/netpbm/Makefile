# $NetBSD: Makefile,v 1.65 2002/08/25 18:39:18 jlam Exp $

DISTNAME=	netpbm-9.25
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netpbm/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://netpbm.sourceforge.net/
COMMENT=	toolkit for conversion of images between different formats

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes

REPLACE_PERL=	pnm/pnmquant ppm/ppmfade ppm/ppmrainbow ppm/ppmshadow

INSTALL_TARGET=	install-dev install
MAKE_ENV+=	INSTALL="${INSTALL}" STRIPFLAG="${_STRIPFLAG_INSTALL}"
MAKEFILE=	GNUmakefile

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == NetBSD) && (${MACHINE_ARCH} == arm32)
CFLAGS=
.endif

.if (${OPSYS} == SunOS)
MAKE_ENV+=	NETWORKLD="-lsocket -lnsl"
BUILD_DEPENDS+=	flex>=2.5.4:../../devel/flex
.else
MAKE_ENV+=	NETWORKLD=""
.endif

post-patch:
	${CP} ${WRKSRC}/Makefile.config.in ${WRKSRC}/Makefile.config

post-install:
	${INSTALL_DATA} ${WRKSRC}/shhopt/shhopt.h ${PREFIX}/include

.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
