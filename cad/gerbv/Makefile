# $NetBSD: Makefile,v 1.16 2003/10/26 04:56:58 dmcmahill Exp $
#

DISTNAME=	gerbv-0.15
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
