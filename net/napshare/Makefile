# $NetBSD: Makefile,v 1.14 2005/03/02 13:42:53 wiz Exp $

DISTNAME=	napshare-1.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=napshare/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://napshare.sourceforge.net/
COMMENT=	Fully featured Gnutella P2P client made to run 24/7 unattended

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

CFLAGS+=	${GTKCFLAGS}

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

GTKCFLAGS!=	${PREFIX}/bin/gtk-config --cflags
