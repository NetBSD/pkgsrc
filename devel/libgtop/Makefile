# $NetBSD: Makefile,v 1.44 2000/10/17 18:03:23 jlam Exp $

DISTNAME=		libgtop-1.0.9
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/libgtop/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.home-of-linux.org/gnome/libgtop/

BUILD_DEPENDS=		${PERL5}:../../lang/perl5-base
DEPENDS+=		gettext>=0.10.35nb1:../../devel/gettext
DEPENDS+=		gnome-libs-*:../../x11/gnome-libs
DEPENDS+=		guile-[0-9]*:../../lang/guile

NOT_FOR_PLATFORM=	SunOS

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == NetBSD
.if (${MACHINE_ARCH} != arm32) && (${MACHINE_ARCH} != i386) && \
    (${MACHINE_ARCH} != m68k) && (${MACHINE_ARCH} != mipsel) && \
    (${MACHINE_ARCH} != powerpc) && (${MACHINE_ARCH} != sparc)
IGNORE=			"${PKGNAME} has not yet been ported to ${MACHINE_ARCH}."
IGNORE+=		"Please look at /usr/include/${MACHINE_ARCH}/pcb.h"
IGNORE+=		"and update patches/patch-al appropriately."
IGNORE+=		"(More information can be found in libgtop.info.)"
.endif
.endif

USE_X11BASE=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CPPFLAGS+=		-I${LOCALBASE}/include	# libintl.h

# The following flags are for debugging purposes.  They don't need to
# be used unless you are actively developing/debugging libgtop.
#CPPFLAGS+=		-DLIBGTOP_ENABLE_DEBUG -DLIBGTOP_FATAL_WARNINGS
#CFLAGS+=		-g
#LDFLAGS+=		-g

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-glib-prefix=${LOCALBASE} \
			--with-libgtop-guile --with-catgets
CONFIGURE_ENV+=		AWK="${AWK}" \
			LN_S="${LN} -s" \
			PERL="${PERL5}" \
			CPPFLAGS="${CPPFLAGS}"  \

.include "../../mk/bsd.pkg.mk"
