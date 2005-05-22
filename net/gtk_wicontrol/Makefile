# $NetBSD: Makefile,v 1.16 2005/05/22 20:08:24 jlam Exp $

DISTNAME=	gtk_wicontrol-0.17
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.izawa.org/software/gtk_wicontrol/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.izawa.org/software/gtk_wicontrol/
COMMENT=	GTK+-based Wavelan status meter

ONLY_FOR_PLATFORM=	*BSD-*-*

USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
