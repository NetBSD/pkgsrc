# $NetBSD: Makefile,v 1.4 2001/04/28 14:34:12 drochner Exp $
#

DISTNAME=	sg-0.6.3
PKGNAME=	scigraphica-0.6.3
CATEGORIES=	graphics math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scigraphica/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://scigraphica.sourceforge.net/
COMMENT=	data analysis and technical graphics

DEPENDS+=	gtk+-*:../../x11/gtk
DEPENDS+=	gtk+extra>=0.99.14:../../x11/gtk+extra
DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	libxml-*:../../textproc/libxml
DEPENDS+=	python-*:../../lang/python
DEPENDS+=	py-Numeric-*:../../math/py-Numeric
DEPENDS+=	readline>=4.0:../../devel/readline

USE_X11=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
