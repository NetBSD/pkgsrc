# $NetBSD: Makefile,v 1.3 2004/04/16 18:41:00 drochner Exp $
#

DISTNAME=		liboop-1.0
CATEGORIES=		devel
MASTER_SITES=		http://download.ofb.net/liboop/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.liboop.org/
COMMENT=		Event loop management library

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE+=	liboop.pc.in
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-adns --without-readline \
			--without-glib --without-tcl

.include "../../mk/bsd.pkg.mk"
