# $NetBSD: Makefile,v 1.7 2004/04/26 05:44:05 snj Exp $

DISTNAME=		libgtop-1.0.13
PKGREVISION=		4
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgtop/1.0/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Library to retrieve system information, used in GNOME

BUILD_USES_MSGFMT=	yes

NOT_FOR_PLATFORM=	SunOS-*-*
OSVERSION_SPECIFIC=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == NetBSD
.  if (${MACHINE_ARCH} != alpha) && (${MACHINE_ARCH} != x86_64) && \
	(${MACHINE_ARCH} != arm) && (${MACHINE_ARCH} != arm32) && \
	(${MACHINE_ARCH} != i386) && (${MACHINE_ARCH} != m68k) && \
	(${MACHINE_ARCH} != mipsel) && (${MACHINE_ARCH} != powerpc) && \
	(${MACHINE_ARCH} != sparc) && (${MACHINE_ARCH} != sparc64)
PKG_FAIL_REASON=	"${PKGNAME} has not yet been ported to ${MACHINE_ARCH}."
PKG_FAIL_REASON+=	"Please look at /usr/include/${MACHINE_ARCH}/pcb.h"
PKG_FAIL_REASON+=	"and update patches/patch-al appropriately."
PKG_FAIL_REASON+=	"(More information can be found in libgtop.info.)"
.  endif
.endif

USE_PERL5=		build
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_X11BASE=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_MAKEINFO=		YES
INFO_FILES=		libgtop.info

# The following flags are for debugging purposes.  They don't need to
# be used unless you are actively developing/debugging libgtop.
#CPPFLAGS+=		-DLIBGTOP_ENABLE_DEBUG -DLIBGTOP_FATAL_WARNINGS
#CFLAGS+=		-g
#LDFLAGS+=		-g

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-glib-prefix=${BUILDLINK_PREFIX.glib} \
			--with-catgets --with-libgtop-guile=no
CONFIGURE_ENV+=		AWK="${AWK}" LN_S="${LN} -s" PERL="${PERL5}"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
