# $NetBSD: Makefile,v 1.13 2004/12/03 12:38:26 wiz Exp $

DISTNAME=	napshare-1.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=napshare/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://napshare.sourceforge.net/
COMMENT=	Fully featured Gnutella P2P client made to run 24/7 unattended

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

CFLAGS+=	`${BUILDLINK_PREFIX.gtk}/bin/gtk-config --cflags`

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
