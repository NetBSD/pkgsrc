# $NetBSD: Makefile,v 1.32 2004/10/03 00:18:20 tv Exp $
#

DISTNAME=		libxml-1.8.17
PKGREVISION=		2
CATEGORIES=		textproc devel lang gnome
MASTER_SITES=		ftp://rpmfind.net/pub/veillard/ \
			${MASTER_SITE_GNOME:=sources/libxml/1.8/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://xmlsoft.org/
COMMENT=		XML parser, mainly used by the GNOME project

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	libxml.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
