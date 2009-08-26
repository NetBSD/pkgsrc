# $NetBSD: Makefile,v 1.29 2009/08/26 19:58:19 sno Exp $
#

DISTNAME=		gtk-send-pr-0.4.9
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		http://download.berlios.de/gtk-send-pr/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		mmendez@energyhq.be
HOMEPAGE=		http://gtk-send-pr.berlios.de/index.html
COMMENT=		GTK+ based problem report tool

USE_TOOLS+=		pkg-config

CPPFLAGS.SunOS+=	-Dstrsep=strpbrk
CPPFLAGS.IRIX+=		-Dstrsep=strpbrk
LDFLAGS.IRIX+=		-lgen

.include "../../mail/libesmtp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
