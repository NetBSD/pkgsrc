# $NetBSD: Makefile,v 1.31 2007/11/29 04:04:15 dmcmahill Exp $
#

DISTNAME=	gerbv-1.0.3
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gerbv/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://gerbv.sourceforge.net/
COMMENT=	Gerber file viewer

PKG_INSTALLATION_TYPES= overwrite pkgviews

CONFIGURE_ARGS+=	--enable-exportpng
GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake pkg-config

LIBS+=		-lm

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
