# $NetBSD: Makefile,v 1.24 2004/11/30 18:26:39 wiz Exp $

DISTNAME=	gnotepad+-1.3.3
PKGNAME=	${DISTNAME:S/+//}
PKGREVISION=	10
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnotepad/}

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://gnotepad.sourceforge.net/
COMMENT=	Easy-to-use, yet feature-rich, simple HTML/text editor for X11

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gnome-core/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
