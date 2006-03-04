# $NetBSD: Makefile,v 1.19 2006/03/04 21:30:21 jlam Exp $

DISTNAME=	napshare-1.3
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=napshare/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://napshare.sourceforge.net/
COMMENT=	Fully featured Gnutella P2P client made to run 24/7 unattended

GNU_CONFIGURE=	YES

GTKCFLAGS_CMD=	${BUILDLINK_PREFIX.gtk}/bin/gtk-config --cflags
CFLAGS+=	${GTKCFLAGS_CMD:sh}

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
