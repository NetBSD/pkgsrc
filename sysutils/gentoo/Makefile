# $NetBSD: Makefile,v 1.3 2002/03/15 13:28:49 wiz Exp $
#

DISTNAME=	gentoo-0.11.22
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
