# $NetBSD: Makefile,v 1.10 2004/02/14 05:08:50 dmcmahill Exp $
#

DISTNAME=		libstroke-0.3
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
USE_BUILDLINK3=		YES

#CONFIGURE_ENV+=		X_CFLAGS="-I${LOCALBASE}/include"

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
