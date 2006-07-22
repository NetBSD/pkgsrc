# $NetBSD: Makefile,v 1.41 2006/07/22 04:46:18 rillig Exp $

DISTNAME=	scribus-1.2.4.1
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.scribus.org.uk/downloads/1.2.4.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.scribus.net/
COMMENT=	Publishing layout with graphical interface

USE_TOOLS+=		gmake perl
USE_LANGUAGES=		c c++
PTHREAD_OPTS+=		require

USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	# empty

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=        --with-qt-dir=${QTDIR:Q} \
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
.include "../../graphics/libart2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
