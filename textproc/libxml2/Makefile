# $NetBSD: Makefile,v 1.34 2003/07/17 22:54:29 grant Exp $

DISTNAME=	libxml2-${LIBXML_VERSION}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxml2/2.5/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	XML parser library from the GNOME project

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libxml-2.0.pc.in

LIBXML_VERSION=		2.5.8
PLIST_SUBST+=		LIBXML_VERSION=${LIBXML_VERSION}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--without-python

MAKE_ENV+=		PAX=${PAX:Q}

TEST_TARGET=		check

CFLAGS+=	-DXML_SGML_DEFAULT_CATALOG=\"\\\"${SGML_DEFAULT_CATALOG}\\\"\"
CFLAGS+=	-DXML_XML_DEFAULT_CATALOG=\"\\\"${XML_DEFAULT_CATALOG}\\\"\"

.include "../../devel/zlib/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
