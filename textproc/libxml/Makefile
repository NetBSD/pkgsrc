# $NetBSD: Makefile,v 1.43 2013/12/23 11:57:06 wiz Exp $

DISTNAME=		libxml-1.8.17
PKGREVISION=		4
CATEGORIES=		textproc devel lang gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libxml/1.8/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xmlsoft.org/
COMMENT=		XML parser (version 1), mainly used by the GNOME project
LICENSE=		gnu-lgpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	libxml.pc.in

# Making all in doc
# bmake: bmake: don't know how to make libxml/tree.h. Stop
MAKE_JOBS_SAFE=		no

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
