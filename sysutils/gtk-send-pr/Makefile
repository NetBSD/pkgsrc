# $NetBSD: Makefile,v 1.25 2007/12/22 10:57:12 obache Exp $
#

DISTNAME=		gtk-send-pr-0.4.9
CATEGORIES=		sysutils
MASTER_SITES=		http://download.berlios.de/gtk-send-pr/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		mmendez@energyhq.be
HOMEPAGE=		http://gtk-send-pr.berlios.de/index.html
COMMENT=		GTK+ based problem report tool

USE_TOOLS+=		pkg-config

CPPFLAGS.SunOS+=	-Dstrsep=strpbrk

.include "../../mail/libesmtp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
