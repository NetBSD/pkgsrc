# $NetBSD: Makefile,v 1.10 2004/04/25 08:29:22 snj Exp $

DISTNAME=	napshare-1.1
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=napshare/}

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://napshare.sourceforge.net/
COMMENT=	Fully featured Gnutella P2P client made to run 24/7 unattended

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--with-gtk-prefix="${BUILDLINK_PREFIX.gtk}"

CFLAGS+=	`${BUILDLINK_PREFIX.gtk}/bin/gtk-config --cflags`

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
