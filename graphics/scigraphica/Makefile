# $NetBSD: Makefile,v 1.13 2002/09/22 10:50:44 jlam Exp $
#

DISTNAME=	scigraphica-0.8.0
PKGREVISION=	1
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
.include "../../textproc/libxml/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gtk+extra/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
