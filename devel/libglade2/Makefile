# $NetBSD: Makefile,v 1.1.1.1 2002/07/12 17:33:14 wiz Exp $
#

DISTNAME=		libglade-2.0.0
PKGNAME=		libglade2-2.0.0
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.0/sources/libglade/}

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://www.daa.com.au/~james/gnome/
COMMENT=		Runtime interpreter for GLADE gui files (v2)

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../textproc/libxml2/buildlink.mk"
.include "../../x11/gtk2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
