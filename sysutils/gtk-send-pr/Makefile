# $NetBSD: Makefile,v 1.4 2004/04/20 19:29:45 minskim Exp $
#

DISTNAME=		gtk-send-pr-0.3
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		http://www.energyhq.es.eu.org/files/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.energyhq.es.eu.org/gtk-send-pr.html
COMMENT=		GTK+ based problem report tool

USE_BUILDLINK3=		yes
USE_X11=		yes

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mail/libesmtp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
