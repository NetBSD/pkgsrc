# $NetBSD: Makefile,v 1.55 2001/11/27 21:03:07 tron Exp $

DISTNAME=		libgtop-1.0.12
PKGNAME=		${DISTNAME}nb1
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/libgtop/}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.home-of-linux.org/gnome/libgtop/
COMMENT=		library to retrieve system information, used in GNOME

BUILD_DEPENDS=		perl>=${PERL5_REQD}:../../lang/perl5
BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome-libs-[0-9]*:../../x11/gnome-libs
DEPENDS+=		guile-[0-9]*:../../lang/guile

NOT_FOR_PLATFORM=	SunOS-*-*
OSVERSION_SPECIFIC=	yes

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == NetBSD
.if (${MACHINE_ARCH} != alpha) && (${MACHINE_ARCH} != arm32) && \
    (${MACHINE_ARCH} != i386) && (${MACHINE_ARCH} != m68k) && \
    (${MACHINE_ARCH} != mipsel) && (${MACHINE_ARCH} != powerpc) && \
    (${MACHINE_ARCH} != sparc)
IGNORE=			"${PKGNAME} has not yet been ported to ${MACHINE_ARCH}."
IGNORE+=		"Please look at /usr/include/${MACHINE_ARCH}/pcb.h"
IGNORE+=		"and update patches/patch-al appropriately."
IGNORE+=		"(More information can be found in libgtop.info.)"
.endif
.endif

USE_X11BASE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_LIBINTL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CPPFLAGS+=		-I${LOCALBASE}/include	# libintl.h

# The following flags are for debugging purposes.  They don't need to
# be used unless you are actively developing/debugging libgtop.
#CPPFLAGS+=		-DLIBGTOP_ENABLE_DEBUG -DLIBGTOP_FATAL_WARNINGS
#CFLAGS+=		-g
#LDFLAGS+=		-g

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-glib-prefix=${LOCALBASE}
CONFIGURE_ARGS+=	--with-libgtop-guile --with-catgets
CONFIGURE_ENV+=		AWK="${AWK}"
CONFIGURE_ENV+=		LN_S="${LN} -s"
CONFIGURE_ENV+=		PERL="${PERL5}"

.include "../../mk/bsd.pkg.mk"
