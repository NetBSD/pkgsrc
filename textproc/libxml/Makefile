# $NetBSD: Makefile,v 1.37 2007/10/25 20:20:59 rillig Exp $
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

# Making all in doc
# bmake: bmake: don't know how to make libxml/tree.h. Stop
MAKE_JOBS_SAFE=		no

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
