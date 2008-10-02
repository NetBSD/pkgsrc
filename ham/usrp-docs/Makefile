# $NetBSD: Makefile,v 1.4 2008/10/02 13:58:52 joerg Exp $

PKGNAME=	usrp-docs-${VERSION}
COMMENT=	Documentation for the usrp module
PKGREVISION=	1

.include "../../meta-pkgs/gnuradio/Makefile.common"

USE_TOOLS+=	make
CONFIGURE_ARGS+=--enable-doxygen
CONFIGURE_ARGS+=--docdir=${LOCALBASE}/share/doc/gnuradio/usrp

BUILD_DEPENDS+=doxygen>=1.4.7:../../devel/doxygen

do-build:
	cd ${WRKSRC}/usrp/doc && make

do-install:
	cd ${WRKSRC}/usrp/doc && make install

.include "../../ham/usrp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
