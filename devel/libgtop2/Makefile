# $NetBSD: Makefile,v 1.16 2003/12/13 23:20:46 cube Exp $

DISTNAME=		libgtop-2.0.7
PKGNAME=		${DISTNAME:S/-/2-/}
CATEGORIES=		devel gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgtop/2.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Library to retrieve system information, used in GNOME2

BUILD_USES_MSGFMT=	YES

NOT_FOR_PLATFORM=	SunOS-*-*
OSVERSION_SPECIFIC=	YES

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == NetBSD
. if (${MACHINE_ARCH} != alpha) && \
     (${MACHINE_ARCH} != arm) && (${MACHINE_ARCH} != arm32) && \
     (${MACHINE_ARCH} != i386) && (${MACHINE_ARCH} != m68k) && \
     (${MACHINE_ARCH} != mipsel) && (${MACHINE_ARCH} != powerpc) && \
     (${MACHINE_ARCH} != sparc) && (${MACHINE_ARCH} != sparc64)
PKG_FAIL_REASON=	"${PKGNAME} has not yet been ported to ${MACHINE_ARCH}."
PKG_FAIL_REASON+=	"Please look at /usr/include/${MACHINE_ARCH}/pcb.h"
PKG_FAIL_REASON+=	"and update patches/patch-al appropriately."
PKG_FAIL_REASON+=	"(More information can be found in libgtop.info.)"
. endif
.endif

USE_PERL5=		build
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libgtop-2.0.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/support/gnome-support-2.0.pc.in
USE_MAKEINFO=		YES
INFO_FILES=		libgtop2.info
TEXINFO_REQD=		4.6

# The following flags are for debugging purposes.  They don't need to
# be used unless you are actively developing/debugging libgtop.
#CPPFLAGS+=		-DLIBGTOP_ENABLE_DEBUG -DLIBGTOP_FATAL_WARNINGS
#CFLAGS+=		-g
#LDFLAGS+=		-g

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-glib-prefix=${BUILDLINK_PREFIX.glib2}
CONFIGURE_ARGS+=	--with-catgets --with-libgtop-guile=no
CONFIGURE_ENV+=		AWK="${AWK}" LN_S="${LN} -s" PERL="${PERL5}"

.include "../../devel/popt/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
