# $NetBSD: Makefile,v 1.12 2002/09/21 23:46:51 jlam Exp $
#

DISTNAME=	scigraphica-0.8.0
PKGREVISION=	1
CATEGORIES=	graphics math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scigraphica/}

MAINTAINER=	drochner@netbsd.org
HOMEPAGE=	http://scigraphica.sourceforge.net/
COMMENT=	data analysis and technical graphics

USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ENV+=		PYTHONBIN=${PYTHONBIN}
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
PY_PATCHPLIST=		YES
USE_GNU_READLINE=	yes

.include "../../devel/readline/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../lang/python/application.mk"
.include "../../math/py-Numeric/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../x11/gtk+extra/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
