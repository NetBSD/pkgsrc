# $NetBSD: Makefile,v 1.13 2002/04/28 22:12:05 wiz Exp $

DISTNAME=	libxml2-2.4.20
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/libxml/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	XML parser library for GNOME

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--without-python

.include "../../devel/zlib/buildlink.mk"
.include "../../converters/libiconv/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
