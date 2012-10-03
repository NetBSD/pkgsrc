# $NetBSD: Makefile,v 1.15.2.1 2012/10/03 12:07:09 spz Exp $
#

DISTNAME=	gps-${GPS_VERSION}
PKGREVISION=	10
CATEGORIES=	devel
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		http://dragonlace.mirrors.ada.cx/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	draco@marino.st
HOMEPAGE=	http://www.adacore.com/home/products/gnatpro/toolsuite/gps/
COMMENT=	GNAT Programming Studio - IDE for Ada and many other languages
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake sed perl awk pkg-config

GPS_VERSION=		5.0.1
USE_LANGUAGES=		c ada c++ fortran
MY_CONFIGURE_ENV+=	ADA_PROJECT_PATH=${APP}
MY_CONFIGURE_ENV+=	PYTHON=${PREFIX}/bin/python${PYVERSSUFFIX}
APP=			${PREFIX}/lib/gnat

.include "options.mk"

CONFIGURE_ARGS+=	--with-gmp=${PREFIX}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MY_CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}
do-build:
	cd ${WRKSRC} && ${SETENV} ADA_PROJECT_PATH=${APP} gmake default

pre-install:
.if !empty(PKG_OPTIONS:Mpython)
	${PY_COMPILE_ALL} ${WRKSRC}/share/plug-ins
	${PY_COMPILE_ALL} ${WRKSRC}/share/library
.endif

.include "../../x11/gtkada/buildlink3.mk"
.include "../../textproc/xmlada/buildlink3.mk"
.include "../../devel/gprbuild-aux/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
