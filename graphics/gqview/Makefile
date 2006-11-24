# $NetBSD: Makefile,v 1.63 2006/11/24 14:37:27 rillig Exp $

DISTNAME=	gqview-2.0.3
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://gqview.sourceforge.net/
COMMENT=	GTK2-based graphic file viewer

USE_TOOLS+=		msgfmt pkg-config
GNU_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	yes
LIBS.SunOS+=		-lsocket

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
