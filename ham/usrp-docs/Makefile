# $NetBSD: Makefile,v 1.2 2007/04/04 16:30:49 joerg Exp $

PKGNAME=	usrp-docs-${VERSION}
PKGREVISION=	1
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
