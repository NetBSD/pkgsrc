# $NetBSD: Makefile,v 1.14 2003/01/28 23:00:55 jmmv Exp $
#

DISTNAME=	scigraphica-0.8.0
PKGREVISION=	2
CATEGORIES=	graphics math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scigraphica/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://scigraphica.sourceforge.net/
COMMENT=	data analysis and technical graphics

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GMAKE=		YES
USE_GNU_READLINE=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ENV+=		PYTHONBIN=${PYTHONBIN}

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

PY_PATCHPLIST=		YES

.include "../../lang/python/application.mk"

.include "../../devel/readline/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../math/py-Numeric/buildlink2.mk"
.include "../../misc/gnome1-dirs/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gtk+extra/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
