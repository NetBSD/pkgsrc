# $NetBSD: Makefile,v 1.17 2003/07/21 16:44:35 martti Exp $

DISTNAME=	gnotepad+-1.3.3
PKGNAME=	${DISTNAME:S/+//}
PKGREVISION=	5
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnotepad/}

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://gnotepad.sourceforge.net/
COMMENT=	Easy-to-use, yet feature-rich, simple HTML/text editor for X11

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
