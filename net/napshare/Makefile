# $NetBSD: Makefile,v 1.21 2008/07/14 12:56:10 joerg Exp $

DISTNAME=	napshare-1.3
PKGREVISION=	1
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
