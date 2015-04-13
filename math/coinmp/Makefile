# $NetBSD: Makefile,v 1.2 2015/04/13 08:17:41 wiz Exp $

DISTNAME=	CoinMP-1.8.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	http://www.coin-or.org/download/source/CoinMP/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://projects.coin-or.org/CoinMP
COMMENT=	CoinMP is a C-API library that supports CLP, CBC, and CGL
LICENSE=	cpl-1.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++ fortran

PKGCONFIG_OVERRIDE+=	Cbc/cbc.pc.in
PKGCONFIG_OVERRIDE+=	Cbc/osi-cbc.pc.in
PKGCONFIG_OVERRIDE+=	Cgl/cgl.pc.in
PKGCONFIG_OVERRIDE+=	Clp/src/OsiClp/osi-clp.pc.in
PKGCONFIG_OVERRIDE+=	Clp/clp.pc.in
PKGCONFIG_OVERRIDE+=	CoinMP/coinmp.pc.in
PKGCONFIG_OVERRIDE+=	CoinUtils/coinutils.pc.in
PKGCONFIG_OVERRIDE+=	Data/Sample/coindatasample.pc.in
PKGCONFIG_OVERRIDE+=	Osi/src/OsiGlpk/osi-glpk.pc.in
PKGCONFIG_OVERRIDE+=	Osi/src/OsiSpx/osi-soplex.pc.in
PKGCONFIG_OVERRIDE+=	Osi/src/OsiMsk/osi-mosek.pc.in
PKGCONFIG_OVERRIDE+=	Osi/src/OsiCpx/osi-cplex.pc.in
PKGCONFIG_OVERRIDE+=	Osi/src/OsiXpr/osi-xpress.pc.in
PKGCONFIG_OVERRIDE+=	Osi/src/OsiGrb/osi-gurobi.pc.in
PKGCONFIG_OVERRIDE+=	Osi/osi-unittests.pc.in
PKGCONFIG_OVERRIDE+=	Osi/osi.pc.in

SUBST_CLASSES+=		pkgconfig
SUBST_STAGE.pkgconfig=	pre-configure
SUBST_MESSAGE.pkgconfig=Set temporary pkg-config directory
SUBST_FILES.pkgconfig+=	*/Makefile.in
SUBST_SED.pkgconfig+=	-e 's,PKG_CONFIG_PATH=@COIN_PKG_CONFIG_PATH@,PKG_CONFIG_PATH=@COIN_PKG_CONFIG_PATH@:${DESTDIR}${PREFIX}/lib/pkgconfig,'
SUBST_SED.pkgconfig+=	-e 's,PKG_CONFIG_PATH="@COIN_PKG_CONFIG_PATH@",PKG_CONFIG_PATH=@COIN_PKG_CONFIG_PATH@:${DESTDIR}${PREFIX}/lib/pkgconfig,'

.include "../../mk/bsd.pkg.mk"
