# $NetBSD: Makefile,v 1.6 2001/09/27 23:18:13 jlam Exp $
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
DEPENDS+=	py-Numeric-[0-9]*:../../math/py-Numeric
DEPENDS+=	readline>=4.0:../../devel/readline

USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--without-gnome
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_PYTHON=	yes
PY_PATCHPLIST=	yes

.include "../../mk/bsd.pkg.mk"
