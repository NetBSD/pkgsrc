# $NetBSD: Makefile,v 1.6 2002/11/30 23:21:36 salo Exp $

DISTNAME=		libbonobo-2.0.0
PKGREVISION=		2
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libbonobo/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://developer.gnome.org/
COMMENT=		GNOME2 Object activation framework library

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/bonobo-activation/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
