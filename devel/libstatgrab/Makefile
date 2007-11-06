# $NetBSD: Makefile,v 1.14 2007/11/06 21:17:34 reed Exp $

DISTNAME=	libstatgrab-0.12
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.uk.i-scream.org/pub/i-scream/libstatgrab/ \
		ftp://ftp.i-scream.org/pub/i-scream/libstatgrab/ \
		http://ftp.i-scream.org/pub/i-scream/libstatgrab/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.i-scream.org/libstatgrab/
COMMENT=	Provides a useful interface to system statistics

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=		pkg-config perl:run
PKGCONFIG_OVERRIDE=	libstatgrab.pc.in

REPLACE_PERL+=	src/statgrab/statgrab-make-mrtg-config.in
REPLACE_PERL+=	src/statgrab/statgrab-make-mrtg-index.in

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

.include "../../mk/bsd.pkg.mk"
