# $NetBSD: Makefile,v 1.17 2001/06/11 02:05:15 jlam Exp $
#

DISTNAME=		libxml-1.8.13
CATEGORIES=		textproc devel lang gnome
MASTER_SITES=		ftp://rpmfind.net/pub/veillard/ \
			${MASTER_SITE_GNOME:=stable/sources/libxml/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://xmlsoft.org/
COMMENT=		XML parser, mainly used by the GNOME project

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/zlib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
