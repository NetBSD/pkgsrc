# $NetBSD: Makefile,v 1.23 2003/03/04 16:52:07 wiz Exp $

DISTNAME=	libxml2-${LIBXML_VERSION}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxml2/2.5/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	XML parser library for GNOME

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libxml-2.0.pc.in

LIBXML_VERSION=		2.5.4
PLIST_SUBST+=		LIBXML_VERSION=${LIBXML_VERSION}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--with-threads

CFLAGS+=	-DXML_SGML_DEFAULT_CATALOG=\"\\\"${SGML_DEFAULT_CATALOG}\\\"\"
CFLAGS+=	-DXML_XML_DEFAULT_CATALOG=\"\\\"${XML_DEFAULT_CATALOG}\\\"\"

.include "../../devel/zlib/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
