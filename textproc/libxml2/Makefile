# $NetBSD: Makefile,v 1.14 2002/05/17 13:02:29 martti Exp $

DISTNAME=	libxml2-${LIBXML_VERSION}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/libxml/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	XML parser library for GNOME

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

LIBXML_VERSION=		2.4.21
PLIST_SUBST+=		LIBXML_VERSION=${LIBXML_VERSION}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--without-python

.include "../../devel/zlib/buildlink.mk"
.include "../../converters/libiconv/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
