# $NetBSD: Makefile,v 1.18 2004/10/03 00:13:30 tv Exp $
#

DISTNAME=		libole2-0.2.4
PKGREVISION=		2
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libole2/0.2/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		OLE2 streams parsing library for GNOME

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES

.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
