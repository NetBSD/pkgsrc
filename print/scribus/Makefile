# $NetBSD: Makefile,v 1.27 2005/10/06 18:00:39 drochner Exp $

DISTNAME=	scribus-1.2.3
CATEGORIES=	print
MASTER_SITES=	http://www.scribus.org.uk/downloads/1.2.3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.scribus.net/
COMMENT=	Publishing layout with graphical interface

USE_TOOLS+=		gmake
PTHREAD_OPTS+=		require

USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=        --with-qt-dir=${QTDIR} \
			--with-extra-libs=${LOCALBASE}/lib \
			--with-extra-includes=${LOCALBASE}/include
# avoid CUPS libs to be pulled in
CONFIGURE_ENV+=		ac_cv_prog_hacups=no

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
