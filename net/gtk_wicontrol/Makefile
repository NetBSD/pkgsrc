# $NetBSD: Makefile,v 1.13 2004/04/25 08:42:29 snj Exp $

DISTNAME=	gtk_wicontrol-0.17
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.izawa.org/software/gtk_wicontrol/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.izawa.org/software/gtk_wicontrol/
COMMENT=	GTK+-based Wavelan status meter

ONLY_FOR_PLATFORM=	*BSD-*-*

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
