# $NetBSD: Makefile,v 1.8 2001/10/01 13:34:49 rh Exp $
#

DISTNAME=		libole2-0.2.3
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/libole2/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		OLE2 streams parsing library for GNOME

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/glib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
