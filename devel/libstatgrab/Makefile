# $NetBSD: Makefile,v 1.3 2004/10/03 00:13:31 tv Exp $

DISTNAME=	libstatgrab-0.10.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.uk.i-scream.org/pub/i-scream/libstatgrab/ \
		http://ftp.uk.i-scream.org/pub/i-scream/libstatgrab/ \
		ftp://ftp2.uk.i-scream.org/sites/ftp.i-scream.org/pub/i-scream/libstatgrab/ \
		http://ftp2.uk.i-scream.org/sites/ftp.i-scream.org/pub/i-scream/libstatgrab/ \
		ftp://ftp.i-scream.org/pub/i-scream/libstatgrab/ \
		http://ftp.i-scream.org/pub/i-scream/libstatgrab/

MAINTAINER=	tim@bishnet.net
HOMEPAGE=	http://www.i-scream.org/libstatgrab/
COMMENT=	Provides a useful interface to system statistics

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_BUILDLINK3=	yes

PKGCONFIG_OVERRIDE=	libstatgrab.pc.in

CONFIGURE_ARGS+=	--disable-examples

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		WITHOUT_STATGRAB
BUILD_DEFS+=		WITHOUT_SAIDAR

.if defined(WITHOUT_STATGRAB)
CONFIGURE_ARGS+=	--disable-statgrab
PLIST_SUBST+=		STATGRAB="@comment "
.else
PLIST_SUBST+=		STATGRAB=""
.endif

.if defined(WITHOUT_SAIDAR)
CONFIGURE_ARGS+=	--disable-saidar
PLIST_SUBST+=		SAIDAR="@comment "
.else
PLIST_SUBST+=		SAIDAR=""
.include "../../devel/ncurses/buildlink3.mk"
.endif

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
