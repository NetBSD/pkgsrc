# $NetBSD: Makefile,v 1.8 2004/10/03 00:18:15 tv Exp $

DISTNAME=		libgtop-2.8.0
PKGNAME=		${DISTNAME:S/-/2-/}
PKGREVISION=	1
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgtop/2.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Library to retrieve system information, used in GNOME2

BUILD_USES_MSGFMT=	YES

NOT_FOR_PLATFORM=	SunOS-*-*
OSVERSION_SPECIFIC=	YES
USE_MSGFMT_PLURALS=	YES

USE_PERL5=		build
USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	libgtop-2.0.pc.in
PKGCONFIG_OVERRIDE+=	support/gnome-support-2.0.pc.in
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
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ENV+=		AWK="${AWK}" LN_S="${LN} -s" PERL="${PERL5}"

PRINT_PLIST_AWK+=	/^(bin\/libgtop_server2|include\/libgtop-2.0\/glibtop_suid.h)$$/ \
				{ print "$${LIBGTOP_SERVER}" $$0; next }

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == NetBSD
.  if (${MACHINE_ARCH} != alpha) && \
	(${MACHINE_ARCH} != arm) && (${MACHINE_ARCH} != arm32) && \
	(${MACHINE_ARCH} != i386) && (${MACHINE_ARCH} != m68k) && \
	(${MACHINE_ARCH} != mipsel) && (${MACHINE_ARCH} != powerpc) && \
	(${MACHINE_ARCH} != sparc) && (${MACHINE_ARCH} != sparc64) && \
	(${MACHINE_ARCH} != x86_64)
PKG_FAIL_REASON=	"${PKGNAME} has not yet been ported to ${MACHINE_ARCH}."
PKG_FAIL_REASON+=	"Please look at /usr/include/${MACHINE_ARCH}/pcb.h"
PKG_FAIL_REASON+=	"and update ${WRKSRC}/sysdeps/freebsd/prockernel.c appropriately."
PKG_FAIL_REASON+=	"(More information can be found in libgtop.info.)"
.  endif
.endif

.if ${OPSYS} == "Linux"
PLIST_SUBST+=	LIBGTOP_SERVER="@comment "
.else
PLIST_SUBST+=	LIBGTOP_SERVER=""

post-install:
	@${CHMOD} g+s ${PREFIX}/bin/libgtop_server2
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
