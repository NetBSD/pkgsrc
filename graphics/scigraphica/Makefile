# $NetBSD: Makefile,v 1.25 2004/09/21 15:10:26 jlam Exp $
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
