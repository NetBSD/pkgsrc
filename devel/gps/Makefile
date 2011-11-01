# $NetBSD: Makefile,v 1.6 2011/11/01 06:00:56 sbd Exp $
#

DISTNAME=	gps-${GPS_VERSION}
PKGREVISION=	1
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
USE_TOOLS+=		gmake sed perl awk

GPS_VERSION=		5.0.1
FULL_PATH=		/sbin:/bin:/usr/sbin:/usr/bin:${PREFIX}/sbin:${PREFIX}/bin:${PREFIX}/lib/pkgconfig
MY_CONFIGURE_ENV=	PATH=${FULL_PATH}
MY_CONFIGURE_ENV+=	CC=gnatgcc
APP=			${PREFIX}/lib/gnat
TPLS=			${PREFIX}/share/gps/templates

.include "options.mk"

CONFIGURE_ARGS+=	--with-gmp=${PREFIX}

do-wrapper:
	# Disable problematic wrappers
	@${ECHO} "###  Pkgsrc wrappers disabled  ###"

post-patch:
	perl -i -pe "s/set dummy python;/set dummy python${PYVERSSUFFIX};/" \
	${WRKSRC}/gnatlib/configure 

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
