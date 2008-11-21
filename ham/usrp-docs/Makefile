# $NetBSD: Makefile,v 1.5 2008/11/21 23:32:50 wiz Exp $

PKGNAME=	usrp-docs-${VERSION}
COMMENT=	Documentation for the usrp module
PKGREVISION=	2

.include "../../meta-pkgs/gnuradio/Makefile.common"

USE_TOOLS+=	make
CONFIGURE_ARGS+=--enable-doxygen
CONFIGURE_ARGS+=--docdir=${LOCALBASE}/share/doc/gnuradio/usrp

BUILD_DEPENDS+=	doxygen>=1.5.7.1:../../devel/doxygen

do-build:
	cd ${WRKSRC}/usrp/doc && make

do-install:
	cd ${WRKSRC}/usrp/doc && make install

.include "../../ham/usrp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
