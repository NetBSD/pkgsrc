# $NetBSD: Makefile,v 1.17 2003/12/04 17:07:48 xtraeme Exp $
#

DISTNAME=		libIDL-0.8.2
PKGREVISION=		1
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libIDL/0.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		CORBA Interface Definition Language parser

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libIDL-2.0.pc.in
INFO_FILES=		libIDL2.info

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
