# $NetBSD: Makefile,v 1.101 2015/07/08 10:34:46 richard Exp $

DISTNAME=	libxslt-1.1.28
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	ftp://xmlsoft.org/libxslt/ \
		http://xmlsoft.org/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/XSLT/
COMMENT=	XSLT parser library from the GNOME project
LICENSE=	mit # with advertisement clause

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libxml-prefix=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--with-html-subdir=libxslt

PKGCONFIG_OVERRIDE=	libxslt.pc.in
PKGCONFIG_OVERRIDE+=	libexslt.pc.in
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MIRIX-5*)
CPPFLAGS+=	-Dsocklen_t=int
.endif

post-extract:
	cp ${WRKSRC}/libxslt/libxslt.syms ${WRKSRC}/libxslt/libxslt_solaris.syms

.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	opt:-Wl,./libxslt.syms:-Wl,./libxslt_solaris.syms
.endif

BUILD_DEPENDS+=	docbook-xml-[0-9]*:../../textproc/docbook-xml
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.27

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
