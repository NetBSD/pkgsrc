# $NetBSD: Makefile,v 1.25 2005/06/01 18:02:59 jlam Exp $
#

DISTNAME=       spruce-0.5.17
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=spruce/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://spruce.sourceforge.net/
COMMENT=	MIME-aware, GNOME-based email program

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes

.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
