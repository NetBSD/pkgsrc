# $NetBSD: Makefile,v 1.18 2004/01/22 07:21:54 grant Exp $
#

DISTNAME=	gerbv-0.15
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gerbv/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://gerbv.sourceforge.net/
COMMENT=	Gerber file viewer

CONFIGURE_ARGS+=	--enable-exportpng
GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
