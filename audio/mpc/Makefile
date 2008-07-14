# $NetBSD: Makefile,v 1.9 2008/07/14 12:55:58 joerg Exp $

DISTNAME=		mpc-0.12.1
CATEGORIES=		audio
MASTER_SITES=		http://www.musicpd.org/uploads/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		simonb@NetBSD.org
HOMEPAGE=		http://musicpd.org/
COMMENT=		Command-line client for musicpd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
