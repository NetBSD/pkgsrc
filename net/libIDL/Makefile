# $NetBSD: Makefile,v 1.56 2012/09/15 10:06:03 obache Exp $

DISTNAME=	libIDL-0.8.14
PKGREVISION=	4
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libIDL/0.8/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	CORBA Interface Definition Language parser
LICENSE=	gnu-lgpl-v2

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

TEST_TARGET=		check

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
