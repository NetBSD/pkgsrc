# $NetBSD: Makefile,v 1.31 2005/02/06 15:09:23 jmmv Exp $
#

DISTNAME=		libIDL-0.8.5
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libIDL/0.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		CORBA Interface Definition Language parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		lex yacc
CONFIGURE_ENV+=		HAVE_YACC=yes
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	libIDL-2.0.pc.in
INFO_FILES=		libIDL2.info

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
OPSYSVARS+=		CONFIGURE_ENV
CONFIGURE_ENV.SunOS+=	CPP=/usr/lib/cpp
.endif

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
