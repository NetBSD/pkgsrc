# $NetBSD: Makefile,v 1.7 2002/10/30 03:09:36 rh Exp $
#

DISTNAME=		libIDL-0.7.4
PKGREVISION=		2
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libIDL/0.7/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		CORBA Interface Definition Language parser

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libIDL-2.0.pc.in

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
