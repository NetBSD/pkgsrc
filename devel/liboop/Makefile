# $NetBSD: Makefile,v 1.10 2017/12/24 09:56:07 wiz Exp $

DISTNAME=		liboop-1.0
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://ftp.lysator.liu.se/pub/liboop/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.lysator.liu.se/liboop/
COMMENT=		Event loop management library

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE+=	liboop.pc.in
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-adns --without-readline \
			--without-glib --without-tcl

.include "../../mk/bsd.pkg.mk"
