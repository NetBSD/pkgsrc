# $NetBSD: Makefile,v 1.36 2005/12/27 18:25:07 reed Exp $
#

DISTNAME=		libxml-1.8.17
PKGREVISION=		3
CATEGORIES=		textproc devel lang gnome
MASTER_SITES=		ftp://rpmfind.net/pub/veillard/ \
			${MASTER_SITE_GNOME:=sources/libxml/1.8/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://xmlsoft.org/
COMMENT=		XML parser (version 1), mainly used by the GNOME project

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	libxml.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
