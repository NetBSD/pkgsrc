# $NetBSD: Makefile,v 1.15 2003/08/19 00:06:44 dmcmahill Exp $
#

DISTNAME=	gerbv-0.14
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gerbv/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://gerbv.sourceforge.net
COMMENT=	Gerber file viewer

CONFIGURE_ARGS+=	--enable-exportpng
GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
