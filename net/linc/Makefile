# $NetBSD: Makefile,v 1.1.1.1 2002/04/23 12:17:22 rh Exp $
#

DISTNAME=	linc-0.1.21
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=pre-gnome2/sources/linc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	network client/server library

BUILD_DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

.include "../../devel/pkgconfig/buildlink.mk"
.include "../../devel/glib2/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
