# $NetBSD: Makefile,v 1.2 2002/09/07 03:24:12 rh Exp $
#

DISTNAME=		libglade-2.0.1
PKGNAME=		libglade2-2.0.1
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.1/sources/libglade/}

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://www.daa.com.au/~james/gnome/
COMMENT=		Runtime interpreter for GLADE gui files (v2)

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
