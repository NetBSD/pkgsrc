# $NetBSD: Makefile,v 1.31.6.1 2004/11/24 22:40:34 salo Exp $
#

DISTNAME=		libxml-1.8.17
PKGREVISION=		3
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
