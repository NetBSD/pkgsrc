# $NetBSD: Makefile,v 1.13 2002/07/18 15:51:16 wiz Exp $

DISTNAME=	gtm-0.4.11

CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtm/}

MAINTAINER=	magick@zhadum.de
HOMEPAGE=	http://gtm.sourceforge.net/
COMMENT=	Gnome Transfer Manager

DEPENDS+=	wget-[0-9]*:../../net/wget

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_BUILDLINK_ONLY=	YES

#post-install:
#	${RMDIR} ${PREFIX}/share/gnome/help/gtm/C/images

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
