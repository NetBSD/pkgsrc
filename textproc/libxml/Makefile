# $NetBSD: Makefile,v 1.24 2002/08/26 10:21:04 martti Exp $
#

DISTNAME=		libxml-1.8.17
CATEGORIES=		textproc devel lang gnome
MASTER_SITES=		ftp://rpmfind.net/pub/veillard/ \
			${MASTER_SITE_GNOME:=stable/sources/libxml/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://xmlsoft.org/
COMMENT=		XML parser, mainly used by the GNOME project

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
