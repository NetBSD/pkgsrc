# $NetBSD: Makefile,v 1.36 2006/07/02 10:21:14 rillig Exp $
#

DISTNAME=	scigraphica-2.1.0
CATEGORIES=	graphics math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scigraphica/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://scigraphica.sourceforge.net/
COMMENT=	Data analysis and technical graphics

USE_DIRS+=		gnome1-1.5
USE_TOOLS+=		gmake
USE_GNU_READLINE=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-gnome
CONFIGURE_ARGS+=	--with-readline-include-path=${BUILDLINK_PREFIX.readline}/include
CONFIGURE_ARGS+=	--with-readline-path=${BUILDLINK_PREFIX.readline}/lib
CONFIGURE_ARGS+=	--with-termcap-include-path=${BUILDLINK_PREFIX.readline}/include
CONFIGURE_ARGS+=	--with-termcap-path=${BUILDLINK_PREFIX.readline}/lib
CONFIGURE_ENV+=		PYTHONBIN=${PYTHONBIN:Q}

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

PTHREAD_AUTO_VARS=	yes

.include "../../lang/python/application.mk"
.include "../../graphics/libscigraphica/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
