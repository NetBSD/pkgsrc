# $NetBSD: Makefile,v 1.16 2005/03/19 17:00:32 tv Exp $

DISTNAME=	napshare-1.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=napshare/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://napshare.sourceforge.net/
COMMENT=	Fully featured Gnutella P2P client made to run 24/7 unattended

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

GTKCFLAGS_CMD=	${BUILDLINK_PREFIX.gtk}/bin/gtk-config --cflags
CFLAGS+=	${GTKCFLAGS_CMD:sh}

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
