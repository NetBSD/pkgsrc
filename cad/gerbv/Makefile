# $NetBSD: Makefile,v 1.20 2004/04/25 04:16:43 xtraeme Exp $
#

DISTNAME=	gerbv-0.15
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gerbv/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://gerbv.sourceforge.net/
COMMENT=	Gerber file viewer

PKG_INSTALLATION_TYPES= overwrite pkgviews

CONFIGURE_ARGS+=	--enable-exportpng
GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
