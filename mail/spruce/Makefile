# $NetBSD: Makefile,v 1.24 2005/05/22 20:08:12 jlam Exp $
#

DISTNAME=       spruce-0.5.17
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spruce/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://spruce.sourceforge.net/
COMMENT=	MIME-aware, GNOME-based email program

USE_X11=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes

.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
