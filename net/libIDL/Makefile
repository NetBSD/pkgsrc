# $NetBSD: Makefile,v 1.1.1.1 2002/04/23 12:21:40 rh Exp $
#

DISTNAME=		libIDL-0.7.4
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=pre-gnome2/sources/libIDL/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		CORBA Interface Definition Language parser

USE_LIBTOOL=		YES
USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../converters/libiconv/buildlink.mk"
.include "../../devel/pkgconfig/buildlink.mk"
.include "../../devel/glib2/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
