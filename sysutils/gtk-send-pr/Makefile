# $NetBSD: Makefile,v 1.18 2005/08/10 20:56:24 jlam Exp $
#

DISTNAME=		gtk-send-pr-0.4.5
CATEGORIES=		sysutils
MASTER_SITES=		http://www.energyhq.es.eu.org/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		flynn@energyhq.es.eu.org
HOMEPAGE=		http://www.energyhq.es.eu.org/gtk-send-pr.html
COMMENT=		GTK+ based problem report tool

USE_TOOLS+=		pkg-config

.include "../../mail/libesmtp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
