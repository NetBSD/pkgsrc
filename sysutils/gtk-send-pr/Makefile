# $NetBSD: Makefile,v 1.1.1.1 2003/12/13 18:09:36 xtraeme Exp $
#

DISTNAME=		gtk-send-pr-0.3
CATEGORIES=		sysutils
MASTER_SITES=		http://www.energyhq.es.eu.org/files/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.energyhq.es.eu.org/gtk-send-pr.html
COMMENT=		GTK+ based problem report tool

USE_BUILDLINK2=		yes
USE_X11=		yes

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mail/libesmtp/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
