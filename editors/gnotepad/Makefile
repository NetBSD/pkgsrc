# $NetBSD: Makefile,v 1.26 2005/04/11 21:45:40 tv Exp $

DISTNAME=	gnotepad+-1.3.3
PKGNAME=	${DISTNAME:S/+//}
PKGREVISION=	10
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnotepad/}

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://gnotepad.sourceforge.net/
COMMENT=	Easy-to-use, yet feature-rich, simple HTML/text editor for X11

BUILD_USES_MSGFMT=	YES

USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gnome-core/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
