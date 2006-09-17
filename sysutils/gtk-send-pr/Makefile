# $NetBSD: Makefile,v 1.23 2006/09/17 12:08:09 wiz Exp $
#

DISTNAME=		gtk-send-pr-0.4.7
CATEGORIES=		sysutils
MASTER_SITES=		http://download.berlios.de/gtk-send-pr/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		flynn@energyhq.es.eu.org
HOMEPAGE=		http://gtk-send-pr.berlios.de/index.html
COMMENT=		GTK+ based problem report tool

USE_TOOLS+=		pkg-config

CPPFLAGS.SunOS+=	-Dstrsep=strpbrk

.include "../../mail/libesmtp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
