# $NetBSD: Makefile,v 1.26 2004/09/24 15:31:44 jlam Exp $
#

DISTNAME=	scigraphica-0.8.0
PKGREVISION=	6
CATEGORIES=	graphics math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scigraphica/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://scigraphica.sourceforge.net/
COMMENT=	Data analysis and technical graphics

USE_BUILDLINK3=		YES
USE_DIRS+=		gnome1-1.5
USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_GNU_READLINE=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--with-readline-include-path=${BUILDLINK_PREFIX.readline}/include
CONFIGURE_ARGS+=	--with-readline-path=${BUILDLINK_PREFIX.readline}/lib
CONFIGURE_ARGS+=	--with-termcap-include-path=${BUILDLINK_PREFIX.readline}/include
CONFIGURE_ARGS+=	--with-termcap-path=${BUILDLINK_PREFIX.readline}/lib
CONFIGURE_ENV+=		PYTHONBIN=${PYTHONBIN}

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

PY_PATCHPLIST=		YES

.include "../../lang/python/application.mk"

.include "../../devel/readline/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gtk+extra/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
