# $NetBSD: Makefile,v 1.8 2002/01/19 16:06:39 drochner Exp $
#

DISTNAME=	sg-0.7.0
PKGNAME=	scigraphica-0.7.0
CATEGORIES=	graphics math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scigraphica/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://scigraphica.sourceforge.net/
COMMENT=	data analysis and technical graphics

DEPENDS+=	gtk+-[0-9]*:../../x11/gtk
DEPENDS+=	gtk+extra>=0.99.14:../../x11/gtk+extra
DEPENDS+=	imlib-[0-9]*:../../graphics/imlib
DEPENDS+=	libxml-[0-9]*:../../textproc/libxml
DEPENDS+=	readline>=4.0:../../devel/readline

USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ENV+=	PYTHONBIN=${PYTHONBIN}
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
PY_PATCHPLIST=	yes

.include "../../lang/python/application.buildlink.mk"
.include "../../math/py-Numeric/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
