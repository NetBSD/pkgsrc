# $NetBSD: Makefile,v 1.12 2004/03/08 19:52:51 minskim Exp $
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

.include "../../lang/tcl83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
