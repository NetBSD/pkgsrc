# $NetBSD: Makefile,v 1.10 2003/02/05 19:19:27 dmcmahill Exp $
#

DISTNAME=	gerbv-0.11
PKGREVISION=	1
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
.include "../../lang/guile14/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
