# $NetBSD: Makefile,v 1.15 2002/09/23 23:57:13 jlam Exp $
#

DISTNAME=	gtm-0.4.11
PKGREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtm/}

MAINTAINER=	magick@zhadum.de
HOMEPAGE=	http://gtm.sourceforge.net/
COMMENT=	Gnome Transfer Manager

DEPENDS+=	wget-[0-9]*:../../net/wget

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES

#post-install:
#	${RMDIR} ${PREFIX}/share/gnome/help/gtm/C/images

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
