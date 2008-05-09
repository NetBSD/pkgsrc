# $NetBSD: Makefile,v 1.11 2008/05/09 12:50:31 drochner Exp $
#

BOOST_PACKAGE=		libs
BOOST_COMMENT=		(binary libraries)
BOOST_CONFIG=		installed
BOOST_INSTALL_LIBS=	yes

PKGREVISION=		1

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
