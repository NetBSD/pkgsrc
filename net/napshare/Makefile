# $NetBSD: Makefile,v 1.23 2012/10/23 17:18:40 asau Exp $

DISTNAME=	napshare-1.3
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=napshare/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://napshare.sourceforge.net/
COMMENT=	Fully featured Gnutella P2P client made to run 24/7 unattended

GNU_CONFIGURE=	YES

USE_TOOLS+=	gmake

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
