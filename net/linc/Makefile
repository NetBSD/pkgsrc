# $NetBSD: Makefile,v 1.4 2002/07/12 15:19:06 wiz Exp $
#

DISTNAME=		linc-0.5.0
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.0/sources/linc/}
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
