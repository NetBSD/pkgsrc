# $NetBSD: Makefile,v 1.13 2005/02/11 12:22:48 jmmv Exp $
#

DISTNAME=		gtk-send-pr-0.4.4
CATEGORIES=		sysutils
MASTER_SITES=		http://www.energyhq.es.eu.org/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		flynn@energyhq.es.eu.org
HOMEPAGE=		http://www.energyhq.es.eu.org/gtk-send-pr.html
COMMENT=		GTK+ based problem report tool

USE_BUILDLINK3=		yes
USE_X11=		yes

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mail/libesmtp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
