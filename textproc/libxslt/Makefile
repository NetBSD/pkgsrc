# $NetBSD: Makefile,v 1.52 2004/12/28 04:37:54 xtraeme Exp $

DISTNAME=	libxslt-1.1.12
PKGNAME=	${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxslt/1.1/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/XSLT/
COMMENT=	XSLT parser library from the GNOME project

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PERL5=		build
PKGCONFIG_OVERRIDE=	libxslt.pc.in
PKGCONFIG_OVERRIDE+=	libexslt.pc.in

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libxml-prefix=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ARGS+=	--without-python

TEST_TARGET=		check

BUILDLINK_DEPENDS.libxml2+=	libxml2>=2.6.8

PKG_OPTIONS_VAR=	PKG_OPTIONS.libxslt
PKG_SUPPORTED_OPTIONS=	crypto
PKG_DEFAULT_OPTIONS+=	crypto
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcrypto)
.  include "../../security/libgcrypt/buildlink3.mk"
CONFIGURE_ARGS+=	--with-crypto
.else
CONFIGURE_ARGS+=	--without-crypto
.endif

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
