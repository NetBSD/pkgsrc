# $NetBSD: Makefile,v 1.8 2001/12/12 18:10:14 wiz Exp $

DISTNAME=	gnotepad+-1.3.3
PKGNAME=	${DISTNAME:S/+//}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnotepad/}

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://gnotepad.sourceforge.net/
COMMENT=	easy-to-use, yet fairly feature-rich, simple HTML and text editor for X11

BUILD_USES_MSGFMT=	yes

USE_X11BASE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_BUILDLINK_ONLY=	YES

GNU_CONFIGURE=	# defined

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
