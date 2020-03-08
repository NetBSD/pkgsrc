# $NetBSD: Makefile,v 1.63 2020/03/08 16:48:03 wiz Exp $

DISTNAME=	libIDL-0.8.14
PKGREVISION=	5
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libIDL/0.8/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	CORBA Interface Definition Language parser
LICENSE=	gnu-lgpl-v2

USE_LIBTOOL=		yes
USE_TOOLS+=		bison flex pkg-config
PKGCONFIG_OVERRIDE=	libIDL-2.0.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		HAVE_YACC=yes
INFO_FILES=		yes

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
CONFIGURE_ENV.SunOS+=	CPP=/usr/lib/cpp
.endif

TEST_TARGET=		check

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
