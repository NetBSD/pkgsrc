# $NetBSD: Makefile,v 1.13 2004/06/03 16:21:14 minskim Exp $
#

DISTNAME=		libstroke-0.5.1
CATEGORIES=		devel
MASTER_SITES=		http://www.etla.net/libstroke/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.etla.net/libstroke/
COMMENT=		Stroke translation library

PKG_INSTALLATION_TYPES= overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11=		YES
USE_BUILDLINK3=		YES
USE_GNU_TOOLS=		make

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ENV+=		ac_cv_path_GTK_CONFIG=no

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
