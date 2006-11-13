# $NetBSD: Makefile,v 1.1.1.1 2006/11/13 18:08:57 wulf Exp $

PKGNAME=	usrp-docs-${VERSION}
COMMENT=	Documentation for the usrp module

.include "../../meta-pkgs/gnuradio/Makefile.common"

USE_TOOLS+=	make
CONFIGURE_ARGS+=--enable-doxygen
CONFIGURE_ARGS+=--docdir=${LOCALBASE}/share/doc/gnuradio/usrp

do-build:
	cd ${WRKSRC}/usrp/doc && make

do-install:
	cd ${WRKSRC}/usrp/doc && make install

.include "../../ham/usrp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
