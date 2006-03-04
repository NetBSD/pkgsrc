# $NetBSD: Makefile,v 1.20 2006/03/04 21:30:19 jlam Exp $

DISTNAME=	gtk_wicontrol-0.17
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://www.izawa.org/software/gtk_wicontrol/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.izawa.org/software/gtk_wicontrol/
COMMENT=	GTK+-based Wavelan status meter

ONLY_FOR_PLATFORM=	*BSD-*-* DragonFly-*-*

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
