# $NetBSD: Makefile,v 1.11 2004/03/08 19:40:36 jmmv Exp $

DISTNAME=	yamt-0.5
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yamt/}

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://yamt.sourceforge.net/
COMMENT=	Yet Another MP3 Tool

BUILD_USES_MSGFMT=	yes
DEPENDS+=	xdg-x11-dirs>=1.1:../../misc/xdg-x11-dirs

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_X11BASE=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
