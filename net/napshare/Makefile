# $NetBSD: Makefile,v 1.7 2003/05/02 14:03:16 wiz Exp $

DISTNAME=	napshare-1.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=napshare/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://napshare.sourceforge.net/
COMMENT=	Fully featured Gnutella P2P client made to run 24/7 unattended

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=--with-gtk-prefix="${BUILDLINK_PREFIX.gtk}"

CFLAGS+=	`${BUILDLINK_PREFIX.gtk}/bin/gtk-config --cflags`

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
