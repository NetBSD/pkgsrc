# $NetBSD: Makefile,v 1.11 2002/10/19 10:54:51 rh Exp $
#

DISTNAME=		libole2-0.2.4
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libole2/0.2/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		OLE2 streams parsing library for GNOME

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
