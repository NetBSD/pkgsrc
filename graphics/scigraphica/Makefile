# $NetBSD: Makefile,v 1.16 2003/05/02 11:55:29 wiz Exp $
#

DISTNAME=	scigraphica-0.8.0
PKGREVISION=	3
CATEGORIES=	graphics math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scigraphica/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://scigraphica.sourceforge.net/
COMMENT=	data analysis and technical graphics

DEPENDS+=	gnome1-dirs>=1.0:../../misc/gnome1-dirs

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
