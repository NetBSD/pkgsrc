# $NetBSD: Makefile,v 1.10 2001/08/17 21:16:45 jlam Exp $
#

DISTNAME=	easytag-0.15
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=easytag/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://easytag.sourceforge.net/
COMMENT=	Tool to view, edit and write ID3 v1&2 TAGs with a GTK+ interface

USE_GMAKE=	yes
#USE_LIBINTL=	yes
USE_X11BASE=	yes

.include "../../audio/id3lib/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"

MAKE_ENV+=	PKGLOCALEDIR=${PKGLOCALEDIR}

.include "../../mk/bsd.pkg.mk"
