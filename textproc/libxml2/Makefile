# $NetBSD: Makefile,v 1.53 2004/04/19 14:24:57 jmmv Exp $

DISTNAME=	libxml2-2.6.9
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxml2/2.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/
COMMENT=	XML parser library from the GNOME project

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	libxml-2.0.pc.in

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=	--with-html-subdir=libxml2
CONFIGURE_ARGS+=	--without-python

# Don't use threads - it's not apparent whether it's necessary or not,
# and this library needs to be usable by non-threaded applications too
CONFIGURE_ARGS+=	--without-threads

# NetBSD-sparc64-1.6*'s f77 makes configure failing and as f77 is not
# needed for this package the following does no harm on other platforms.
CONFIGURE_ENV+=		F77=${FALSE}

MAKE_ENV+=	PAX=${PAX:Q}

TEST_TARGET=	check

CFLAGS+=	-DXML_SGML_DEFAULT_CATALOG=\"\\\"${SGML_DEFAULT_CATALOG}\\\"\"
CFLAGS+=	-DXML_XML_DEFAULT_CATALOG=\"\\\"${XML_DEFAULT_CATALOG}\\\"\"

.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"

.include "../../mk/bsd.pkg.mk"
