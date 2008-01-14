# $NetBSD: Makefile,v 1.53 2008/01/14 12:54:10 drochner Exp $

DISTNAME=		scribus-1.3.3.11
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scribus/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.scribus.net/
COMMENT=		Publishing layout with graphical interface

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++
PTHREAD_OPTS+=		require

USE_DIRS+=		xdg-1.4
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	# empty

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR:Q} \
			--with-extra-libs=${LOCALBASE}/lib \
			--with-extra-includes=${LOCALBASE}/include
# XXX should work with other Python versions, but there are
# stupid assumptions in the configure script
PYTHON_VERSIONS_ACCEPTED=	24
CONFIGURE_ARGS+=	--with-pythondir=${LOCALBASE:Q}
# avoid CUPS libs to be pulled in
CONFIGURE_ENV+=		ac_cv_prog_hacups=no

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
BUILDLINK_API_DEPENDS.libart+= libart>=2.3.19nb1
.include "../../graphics/libart/buildlink3.mk"
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
