# $NetBSD: Makefile,v 1.27 1999/12/20 11:56:31 rh Exp $

DISTNAME=		libgtop-1.0.5
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=gnome-1.0.53/sources/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.home-of-linux.org/gnome/libgtop/

BUILD_DEPENDS=		${PERL}:../../lang/perl5
DEPENDS+=		gettext-0.10.35:../../devel/gettext
DEPENDS+=		gnome-libs-*:../../x11/gnome-libs
DEPENDS+=		guile-*:../../lang/guile

ONLY_FOR_PLATFORM=	NetBSD-*-arm32 NetBSD-*-i386 NetBSD-*-m68k

GNU_CONFIGURE=		yes
USE_X11BASE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes

CFLAGS+=		-g
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-g -L${LOCALBASE}/lib -lintl
PERL=			${LOCALBASE}/bin/perl

# The following CPPFLAGS are for debugging purposes.
CPPFLAGS+=		-DLIBGTOP_ENABLE_DEBUG -DLIBGTOP_FATAL_WARNINGS

CONFIGURE_ARGS+=	--with-glib-prefix=${LOCALBASE} \
			--with-libgtop-guile --with-catgets
CONFIGURE_ENV+=		AWK="${AWK}" \
			CPP="${CPP}" \
			LN_S="${LN} -s" \
			PERL="${PERL}" \
			CPPFLAGS="${CPPFLAGS}"  \
			LOCALBASE=${LOCALBASE} \
			X11BASE=${X11BASE}

.include "../../mk/bsd.pkg.mk"
