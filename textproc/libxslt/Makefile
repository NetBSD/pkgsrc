# $NetBSD: Makefile,v 1.102 2016/02/26 10:32:47 jperkin Exp $

DISTNAME=	libxslt-1.1.28
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	ftp://xmlsoft.org/libxslt/ \
		http://xmlsoft.org/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/XSLT/
COMMENT=	XSLT parser library from the GNOME project
LICENSE=	mit # with advertisement clause

BUILD_DEPENDS+=	docbook-xml-[0-9]*:../../textproc/docbook-xml
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libxml-prefix=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--with-html-subdir=libxslt

PKGCONFIG_OVERRIDE=	libxslt.pc.in
PKGCONFIG_OVERRIDE+=	libexslt.pc.in
TEST_TARGET=		check

BUILDLINK_TRANSFORM.SunOS+=	opt:-Wl,./libxslt.syms:-Wl,./libxslt_solaris.syms

.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MIRIX-5*)
CPPFLAGS+=	-Dsocklen_t=int
.endif

post-extract:
	cp ${WRKSRC}/libxslt/libxslt.syms ${WRKSRC}/libxslt/libxslt_solaris.syms

BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.27

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
