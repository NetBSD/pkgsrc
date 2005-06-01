# $NetBSD: Makefile,v 1.17 2005/06/01 18:02:44 jlam Exp $
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
USE_TOOLS=		gmake

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ENV+=		ac_cv_path_GTK_CONFIG=no

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
