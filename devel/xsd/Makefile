# $NetBSD: Makefile,v 1.5 2009/10/30 19:29:54 joerg Exp $

DISTNAME=		xsd-3.2.0+dep
EXTRACT_SUFX=		.tar.bz2
PKGNAME=		xsd-3.2.0
CATEGORIES=		devel textproc
MASTER_SITES=		http://www.codesynthesis.com/download/xsd/3.2/

MAINTAINER=		hasso@NetBSD.org
HOMEPAGE=		http://www.codesynthesis.com/products/xsd/
COMMENT=		W3C XML Schema to C++ data binding compiler
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		bash gmake gm4
USE_LANGUAGES+=		c++

SUBST_CLASSES+=		rpath
SUBST_STAGE.rpath=	post-configure
SUBST_FILES.rpath=	*/*/*/configuration-dynamic.make
SUBST_SED.rpath=	-e 's|cxx_rpath[ ]*:=[ ]*n|cxx_rpath := y|g'

do-build:
	# XXX: rapth needs a better hack. TODO: add optimization
	cd ${WRKSRC} && LDFLAGS="-Wl,-rpath,${PREFIX}/lib" ./build.sh

do-install:
	cd ${WRKSRC} && MAKEFLAGS="install_prefix=${DESTDIR}${PREFIX} \
	install_man_dir=${DESTDIR}${PREFIX}/man" ./build.sh install

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
