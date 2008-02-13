# $NetBSD: Makefile,v 1.46 2008/02/13 19:33:26 drochner Exp $

DISTNAME=	libIDL-0.8.10
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libIDL/0.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	CORBA Interface Definition Language parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		bison flex pkg-config
PKGCONFIG_OVERRIDE=	libIDL-2.0.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		HAVE_YACC=yes
INFO_FILES=		# PLIST

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
OPSYSVARS+=		CONFIGURE_ENV
CONFIGURE_ENV.SunOS+=	CPP=/usr/lib/cpp
.endif

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE:Q}

TEST_TARGET=		check

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
