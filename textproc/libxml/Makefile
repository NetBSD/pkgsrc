# $NetBSD: Makefile,v 1.16 2001/05/26 21:51:51 jlam Exp $
#

DISTNAME=		libxml-1.8.13
CATEGORIES=		textproc devel lang gnome
MASTER_SITES=		ftp://rpmfind.net/pub/veillard/ \
			${MASTER_SITE_GNOME:=stable/sources/libxml/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://xmlsoft.org/
COMMENT=		XML parser, mainly used by the GNOME project

.include "../../devel/zlib/buildlink.mk"

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CPPFLAGS+=		-I${BUILDLINK_INCDIR}
LDFLAGS+=		-L${BUILDLINK_LIBDIR}

.include "../../mk/bsd.pkg.mk"
