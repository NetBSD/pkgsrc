# $NetBSD: Makefile,v 1.26 2002/10/30 03:09:38 rh Exp $
#

DISTNAME=		libxml-1.8.17
CATEGORIES=		textproc devel lang gnome
MASTER_SITES=		ftp://rpmfind.net/pub/veillard/ \
			${MASTER_SITE_GNOME:=sources/libxml/1.8/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://xmlsoft.org/
COMMENT=		XML parser, mainly used by the GNOME project

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libxml.pc.in

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
