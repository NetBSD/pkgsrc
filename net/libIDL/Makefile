# $NetBSD: Makefile,v 1.25 2004/04/01 18:15:58 jmmv Exp $
#

DISTNAME=		libIDL-0.8.3
PKGREVISION=		1
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libIDL/0.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		CORBA Interface Definition Language parser

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		lex yacc
CONFIGURE_ENV+=		HAVE_YACC=yes
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	libIDL-2.0.pc.in
INFO_FILES=		libIDL2.info

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
