# $NetBSD: Makefile,v 1.11 2003/05/02 11:54:34 wiz Exp $

DISTNAME=		libbonobo-2.2.0
PKGREVISION=		1
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libbonobo/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@netbsd.org
HOMEPAGE=		http://developer.gnome.org/
COMMENT=		GNOME2 Object activation framework library

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS= 	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

.include "../../devel/bonobo-activation/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
