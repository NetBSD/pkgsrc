# $NetBSD: Makefile,v 1.4 2001/09/26 23:22:17 jlam Exp $

DISTNAME=	libxml2-2.4.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/libxml/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	Xml parser library for GNOME

USE_BUILDLINK_ONLY=	yes
REPLACE_BUILDLINK=	xml2-config xml2Conf.sh

USE_GMAKE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

.include "../../devel/zlib/buildlink.mk"
.include "../../converters/libiconv/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
