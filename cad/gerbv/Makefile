# $NetBSD: Makefile,v 1.8 2002/11/22 00:41:14 dmcmahill Exp $
#

DISTNAME=	gerbv-0.11
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gerbv/}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://gerbv.sourceforge.net
COMMENT=	Gerber file viewer

CONFIGURE_ARGS+=	--enable-exportpng
CONFIGURE_ARGS+=	--enable-batch
GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../lang/guile/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
