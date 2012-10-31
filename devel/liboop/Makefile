# $NetBSD: Makefile,v 1.9 2012/10/31 11:17:19 asau Exp $
#

DISTNAME=		liboop-1.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://download.ofb.net/liboop/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.liboop.org/
COMMENT=		Event loop management library

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE+=	liboop.pc.in
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-adns --without-readline \
			--without-glib --without-tcl

.include "../../mk/bsd.pkg.mk"
