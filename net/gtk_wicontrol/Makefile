# $NetBSD: Makefile,v 1.9 2003/06/02 01:17:58 jschauma Exp $

DISTNAME=	gtk_wicontrol-0.17
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.izawa.org/software/gtk_wicontrol/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.izawa.org/software/gtk_wicontrol/
COMMENT=	GTK+-based Wavelan status meter

ONLY_FOR_PLATFORM=	*BSD-*-*

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
