# $NetBSD: Makefile,v 1.11 2002/09/22 00:03:03 jlam Exp $

DISTNAME=	gnotepad+-1.3.3
PKGNAME=	${DISTNAME:S/+//}
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnotepad/}

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://gnotepad.sourceforge.net/
COMMENT=	easy-to-use, yet fairly feature-rich, simple HTML and text editor for X11

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
