# $NetBSD: Makefile,v 1.2 2002/02/11 00:26:03 wiz Exp $
#

DISTNAME=	gentoo-0.11.19
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gentoo/}

MAINTAINER=	dunse@goa.nu
HOMEPAGE=	http://www.obsession.se/gentoo/
COMMENT=	Two-pane filemanager using GTK+, 100% GUI configurable

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
