# $NetBSD: Makefile,v 1.7 2001/06/16 19:51:51 jlam Exp $
#

DISTNAME=	easytag-0.11
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=easytag/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://easytag.sourceforge.net/
COMMENT=	Tool to view, edit and write ID3 v1 TAGs with a GTK+ interface

DEPENDS+=	gtk+>=1.2.8:../../x11/gtk

USE_GMAKE=	yes
#USE_LIBINTL=	yes
USE_X11BASE=	yes

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"

MAKE_ENV+=	GTK_CONFIG="${BUILDLINK_CONFIG_WRAPPER.gtk}"
MAKE_ENV+=	PKGLOCALEDIR=${PKGLOCALEDIR}

.include "../../mk/bsd.pkg.mk"
