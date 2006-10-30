# $NetBSD: Makefile,v 1.69 2006/10/30 21:03:21 drochner Exp $

DISTNAME=	libxslt-1.1.18
CATEGORIES=	textproc
MASTER_SITES=	ftp://xmlsoft.org/libxslt/
#MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxslt/1.1/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/XSLT/
COMMENT=	XSLT parser library from the GNOME project

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=		gmake perl
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	libxslt.pc.in
PKGCONFIG_OVERRIDE+=	libexslt.pc.in

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libxml-prefix=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--without-python

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"
.if !empty(LOWER_OPSYS:Mirix5*)
CPPFLAGS+=	-Dsocklen_t=int
.endif

BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.25

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
