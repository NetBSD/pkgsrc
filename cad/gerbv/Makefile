# $NetBSD: Makefile,v 1.5 2002/07/08 03:30:55 dmcmahill Exp $
#

DISTNAME=	gerbv-0.0.9
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gerbv/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://gerbv.sourceforge.net
COMMENT=	Gerber file viewer

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
CONFIGURE_ARGS+=	--enable-exportpng

.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
