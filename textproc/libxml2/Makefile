# $NetBSD: Makefile,v 1.17 2002/08/31 00:49:24 wiz Exp $

DISTNAME=	libxml2-${LIBXML_VERSION}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/libxml/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	XML parser library for GNOME

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

LIBXML_VERSION=		2.4.24
PLIST_SUBST+=		LIBXML_VERSION=${LIBXML_VERSION}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--without-python

.include "../../devel/zlib/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
