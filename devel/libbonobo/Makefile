# $NetBSD: Makefile,v 1.2 2002/09/10 14:10:46 wiz Exp $

DISTNAME=		libbonobo-2.0.0
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.0/sources/libbonobo/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@hispabsd.org
HOMEPAGE=		http://developer.gnome.org/
COMMENT=		GNOME2 Object activation framework library

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/bonobo-activation/buildlink2.mk"
.include "../../devel/ptl2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
