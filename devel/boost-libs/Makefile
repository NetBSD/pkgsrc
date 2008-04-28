# $NetBSD: Makefile,v 1.10 2008/04/28 21:35:25 jmmv Exp $
#

BOOST_PACKAGE=		libs
BOOST_COMMENT=		(binary libraries)
BOOST_CONFIG=		installed
BOOST_INSTALL_LIBS=	yes

PKG_REVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/boost/Makefile.common"

BJAM_ARGS+=		--without-python

.include "../../devel/boost-jam/bjam.mk"

do-build: bjam-build

do-install: boost-install-libs

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
