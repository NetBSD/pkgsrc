# $NetBSD: Makefile,v 1.37 2000/06/24 16:40:57 danw Exp $

DISTNAME=		libgtop-1.0.9
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/libgtop/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.home-of-linux.org/gnome/libgtop/

BUILD_DEPENDS=		${PERL}:../../lang/perl5
DEPENDS+=		gettext-0.10.*:../../devel/gettext
DEPENDS+=		gnome-libs-*:../../x11/gnome-libs
DEPENDS+=		guile-[0-9]*:../../lang/guile

NOT_FOR_PLATFORM=	SunOS

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == NetBSD
.if (${MACHINE_ARCH} != arm32) && (${MACHINE_ARCH} != i386) && \
    (${MACHINE_ARCH} != m68k) && (${MACHINE_ARCH} != powerpc)
IGNORE=			"has not yet been ported to ${MACHINE_ARCH}."
IGNORE+=		"Please look at /usr/include/${MACHINE_ARCH}/pcb.h"
IGNORE+=		"and update patches/patch-al appropriately."
IGNORE+=		"(More information can be found in libgtop.info.)"
.endif
.endif

GNU_CONFIGURE=		# defined
USE_X11BASE=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

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
