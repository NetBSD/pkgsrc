# $NetBSD: Makefile,v 1.65 2002/11/30 23:21:37 salo Exp $

DISTNAME=		libgtop-1.0.13
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgtop/1.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		library to retrieve system information, used in GNOME

BUILD_USES_MSGFMT=	yes

NOT_FOR_PLATFORM=	SunOS-*-*
OSVERSION_SPECIFIC=	yes

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == NetBSD
.if (${MACHINE_ARCH} != alpha) && (${MACHINE_ARCH} != arm32) && \
    (${MACHINE_ARCH} != i386) && (${MACHINE_ARCH} != m68k) && \
    (${MACHINE_ARCH} != mipsel) && (${MACHINE_ARCH} != powerpc) && \
    (${MACHINE_ARCH} != sparc) && (${MACHINE_ARCH} != sparc64)
IGNORE=			"${PKGNAME} has not yet been ported to ${MACHINE_ARCH}."
IGNORE+=		"Please look at /usr/include/${MACHINE_ARCH}/pcb.h"
IGNORE+=		"and update patches/patch-al appropriately."
IGNORE+=		"(More information can be found in libgtop.info.)"
.endif
.endif

USE_PERL5=		build
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_X11BASE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

# The following flags are for debugging purposes.  They don't need to
# be used unless you are actively developing/debugging libgtop.
#CPPFLAGS+=		-DLIBGTOP_ENABLE_DEBUG -DLIBGTOP_FATAL_WARNINGS
#CFLAGS+=		-g
#LDFLAGS+=		-g

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-glib-prefix=${BUILDLINK_PREFIX.glib} \
			--with-catgets --with-libgtop-guile=no
CONFIGURE_ENV+=		AWK="${AWK}" LN_S="${LN} -s" PERL="${PERL5}"

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
