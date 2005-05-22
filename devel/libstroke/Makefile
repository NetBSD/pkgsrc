# $NetBSD: Makefile,v 1.16 2005/05/22 20:07:53 jlam Exp $
#

DISTNAME=		libstroke-0.5.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.etla.net/libstroke/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.etla.net/libstroke/
COMMENT=		Stroke translation library

PKG_INSTALLATION_TYPES= overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11=		YES
USE_TOOLS=		gmake

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ENV+=		ac_cv_path_GTK_CONFIG=no

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
