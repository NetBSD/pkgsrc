# $NetBSD: Makefile,v 1.22 2011/04/22 13:44:26 obache Exp $

DISTNAME=	napshare-1.3
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=napshare/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://napshare.sourceforge.net/
COMMENT=	Fully featured Gnutella P2P client made to run 24/7 unattended

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

USE_TOOLS+=	gmake

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
