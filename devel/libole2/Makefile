# $NetBSD: Makefile,v 1.16 2004/02/14 17:21:38 jlam Exp $
#

DISTNAME=		libole2-0.2.4
PKGREVISION=		1
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libole2/0.2/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		OLE2 streams parsing library for GNOME

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES

.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
