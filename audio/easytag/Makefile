# $NetBSD: Makefile,v 1.5 2001/02/16 13:30:34 wiz Exp $
#

DISTNAME=	easytag-0.11
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=easytag/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://easytag.sourceforge.net/
COMMENT=	Tool to view, edit and write ID3 v1 TAGs with a GTK+ interface

DEPENDS+=	gtk+>=1.2.8:../../x11/gtk

USE_GMAKE=	yes
USE_LIBINTL=	yes
USE_X11BASE=	yes

.include "../../mk/bsd.pkg.mk"
