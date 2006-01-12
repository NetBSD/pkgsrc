# $NetBSD: Makefile,v 1.4 2006/01/12 22:48:46 joerg Exp $
#

PKGREVISION=	1

BOOST_PACKAGE=		libs
BOOST_COMMENT=		(binary libraries)
BOOST_CONFIG=		installed
BOOST_INSTALL_LIBS=	yes

.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--without-python
BJAM_ARGS+=		--without-serialization # Requires wide I/O

.include "../../devel/boost-build/bjam.mk"

do-build: bjam-build

do-install: boost-install-libs

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
