# $NetBSD: Makefile,v 1.3 2002/04/27 11:31:24 rh Exp $
#

DISTNAME=		linc-0.1.21
PKGREVISION=		1
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=pre-gnome2/sources/linc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		network client/server library

BUILD_DEPENDS+=		gtk-doc-[0-9]*:../../textproc/gtk-doc

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/pkgconfig/buildlink.mk"
.include "../../devel/glib2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
