# $NetBSD: Makefile,v 1.5 2005/06/01 18:03:21 jlam Exp $
#

DISTNAME=	fsv-0.9
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fsv/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fsv.sourceforge.net/
COMMENT=	3D filesystem visualizer

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../x11/gtkglarea/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
