# $NetBSD: Makefile,v 1.11 2009/05/20 00:10:13 asau Exp $

DISTNAME=		mpc-0.15
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=musicpd/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://musicpd.org/
COMMENT=		Command-line client for musicpd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
