# $NetBSD: Makefile,v 1.5 2004/04/20 20:46:39 minskim Exp $
#

DISTNAME=		gtk-send-pr-0.3.3
CATEGORIES=		sysutils
MASTER_SITES=		http://www.energyhq.es.eu.org/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.energyhq.es.eu.org/gtk-send-pr.html
COMMENT=		GTK+ based problem report tool

USE_BUILDLINK3=		yes
USE_X11=		yes

BUILDLINK_TRANSFORM+=	S:-DGTK_DISABLE_DEPRECATED:

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mail/libesmtp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
