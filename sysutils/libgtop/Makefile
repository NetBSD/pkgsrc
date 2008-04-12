# $NetBSD: Makefile,v 1.18 2008/04/12 22:43:12 jlam Exp $

DISTNAME=		libgtop-2.20.2
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgtop/2.20/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Library to retrieve system information, used in GNOME2

OSVERSION_SPECIFIC=	YES

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake makeinfo msgfmt perl pkg-config intltool
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	libgtop-2.0.pc.in
PKGCONFIG_OVERRIDE+=	support/gnome-support-2.0.pc.in
INFO_FILES=		YES
TEXINFO_REQD=		4.6
CONFLICTS+=		libgtop2-[0-9]*

# The following flags are for debugging purposes.  They don't need to
# be used unless you are actively developing/debugging libgtop.
#CPPFLAGS+=		-DLIBGTOP_ENABLE_DEBUG -DLIBGTOP_FATAL_WARNINGS
#CFLAGS+=		-g
#LDFLAGS+=		-g

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-glib-prefix=${BUILDLINK_PREFIX.glib2}
CONFIGURE_ARGS+=	--with-catgets --with-libgtop-guile=no
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ENV+=		LN_S="${LN} -s"

PRINT_PLIST_AWK+=	/^bin\/libgtop_server2$$/ \
				{ print "$${LIBGTOP_SERVER}" $$0; next }
PRINT_PLIST_AWK+=	/^include\/libgtop-2.0\/glibtop_suid.h$$/ \
				{ print "$${LIBGTOP_SUID_H}" $$0; next }

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == NetBSD
CONFIGURE_ENV+=	fu_cv_sys_mounted_getmntinfo=yes
.endif

PLIST_VARS+=	server suid.h
.if ${OPSYS} == "Linux"
#		nothing
.elif ${OPSYS} == "SunOS"
PLIST.server=	yes
.else
PLIST.server=	yes
PLIST.suid.h=	yes
.endif

.if defined(PLIST.server)
post-install:
	${CHMOD} g+s ${PREFIX}/bin/libgtop_server2
.endif

# XXX This needs a check in the configure script, which should be clean
# enough to be integrated in the mainstream sources.
statvfs_h=	/usr/include/sys/statvfs.h
.if exists(${statvfs_h})
reads_count!=	if ${GREP} f_syncreads ${statvfs_h} >/dev/null; then \
		${ECHO} yes; else ${ECHO} no; fi
.  if ${reads_count} == "yes"
CPPFLAGS+=	-DHAVE_STATVFS_READS_COUNT
.  endif
.  undef reads_count

writes_count!=	if ${GREP} f_syncwrites ${statvfs_h} >/dev/null; then \
		${ECHO} yes; else ${ECHO} no; fi
.  if ${writes_count} == "yes"
CPPFLAGS+=	-DHAVE_STATVFS_WRITES_COUNT
.  endif
.  undef writes_count
.endif
.undef statvfs_h

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.0

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
