# $NetBSD: Makefile,v 1.11 2004/02/14 05:09:45 dmcmahill Exp $
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

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../lang/tcl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
