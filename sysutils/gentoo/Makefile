# $NetBSD: Makefile,v 1.5 2002/08/25 21:50:57 jlam Exp $
#

DISTNAME=	gentoo-0.11.31
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gentoo/}

MAINTAINER=	dunse@goa.nu
HOMEPAGE=	http://www.obsession.se/gentoo/
COMMENT=	Two-pane filemanager using GTK+, 100% GUI configurable

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11=	YES

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
