# $NetBSD: Makefile,v 1.29 2004/02/14 17:21:53 jlam Exp $
#

DISTNAME=		libxml-1.8.17
PKGREVISION=		1
CATEGORIES=		textproc devel lang gnome
MASTER_SITES=		ftp://rpmfind.net/pub/veillard/ \
			${MASTER_SITE_GNOME:=sources/libxml/1.8/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://xmlsoft.org/
COMMENT=		XML parser, mainly used by the GNOME project

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	${WRKSRC}/libxml.pc.in

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
