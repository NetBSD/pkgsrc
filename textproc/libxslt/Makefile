# $NetBSD: Makefile,v 1.85 2010/09/08 13:53:00 tez Exp $

DISTNAME=	libxslt-1.1.26
CATEGORIES=	textproc
MASTER_SITES+=	ftp://xmlsoft.org/libxslt/
#MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxslt/1.1/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://xmlsoft.org/XSLT/
COMMENT=	XSLT parser library from the GNOME project
LICENSE=	mit # with advertisement clause

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	libxslt.pc.in
PKGCONFIG_OVERRIDE+=	libexslt.pc.in

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libxml-prefix=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--with-html-subdir=libxslt

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MIRIX-5*)
CPPFLAGS+=	-Dsocklen_t=int
.endif

post-extract:
	cp ${WRKSRC}/libxslt/libxslt.syms ${WRKSRC}/libxslt/libxslt_solaris.syms

.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rename:-Wl,./libxslt.syms:-Wl,./libxslt_solaris.syms
.endif

BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.27

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
