# $NetBSD: Makefile,v 1.6 2006/07/13 17:59:37 heinz Exp $
#

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

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
