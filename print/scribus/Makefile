# $NetBSD: Makefile,v 1.55 2008/10/09 10:33:40 adam Exp $

DISTNAME=		scribus-1.3.3.12
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scribus/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.scribus.net/
COMMENT=		Publishing layout with graphical interface

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=		xdg-1.4
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake perl
PTHREAD_OPTS+=		require
SHLIBTOOL_OVERRIDE=	# empty
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-cairo
CONFIGURE_ARGS+=	--with-extra-includes=${PREFIX}/include
CONFIGURE_ARGS+=	--with-extra-libs=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR}
# XXX should work with other Python versions, but there are
# stupid assumptions in the configure script
PYTHON_VERSIONS_ACCEPTED=	25 24
CONFIGURE_ARGS+=	--with-pythondir=${PREFIX}
# avoid CUPS libs to be pulled in
CONFIGURE_ENV+=		ac_cv_prog_hacups=no

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
BUILDLINK_API_DEPENDS.libart+= libart>=2.3.19nb1
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../databases/shared-mime-info/mimedb.mk"

.include "../../mk/bsd.pkg.mk"
