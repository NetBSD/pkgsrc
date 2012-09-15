# $NetBSD: Makefile,v 1.40 2012/09/15 10:06:29 obache Exp $

DISTNAME=		libgtop-2.28.4
PKGREVISION=		3
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgtop/2.28/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Library to retrieve system information, used in GNOME2

PKG_DESTDIR_SUPPORT=	user-destdir

OSVERSION_SPECIFIC=	YES

GNU_CONFIGURE=		YES
CONFIG_SHELL=		bash
INFO_FILES=		YES
PKGCONFIG_OVERRIDE=	libgtop-2.0.pc.in
TEXINFO_REQD=		4.6
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake makeinfo msgfmt perl pkg-config intltool

CONFIGURE_ARGS+=	--enable-gtk-doc
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ENV+=		LN_S="${LN} -s"

CONFLICTS+=		libgtop2-[0-9]*

post-patch:
	${CP} ${FILESDIR}/procaffinity.c ${WRKSRC}/sysdeps/bsd/

# The following flags are for debugging purposes.  They don't need to
# be used unless you are actively developing/debugging libgtop.
#CPPFLAGS+=		-DLIBGTOP_ENABLE_DEBUG -DLIBGTOP_FATAL_WARNINGS
#CFLAGS+=		-g
#LDFLAGS+=		-g

PRINT_PLIST_AWK+=	/^bin\/libgtop_server2$$/ \
				{ print "$${LIBGTOP_SERVER}" $$0; next }
PRINT_PLIST_AWK+=	/^include\/libgtop-2.0\/glibtop_suid.h$$/ \
				{ print "$${LIBGTOP_SUID_H}" $$0; next }

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == NetBSD
CONFIGURE_ENV+=	fu_cv_sys_mounted_getmntinfo=yes
.endif

INSTALL_MAKE_FLAGS+=	libgtop_postinstall=true
PLIST_VARS+=	server suid.h
.if ${OPSYS} == "AIX"
PLIST.server=	yes
PLIST.suid.h=	yes
SPECIAL_PERMS=	bin/libgtop_server2 ${REAL_ROOT_USER} system 2755
.elif ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly" || \
      ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || \
      ${OPSYS} == "OpenBSD"
PLIST.server=	yes
PLIST.suid.h=	yes
SPECIAL_PERMS=	bin/libgtop_server2 ${REAL_ROOT_USER} kmem 2755
.elif ${OPSYS} == "Linux"
#PLIST.server=	no
#PLIST.suid.h=	no
.elif ${OPSYS} == "SunOS"
PLIST.server=	yes
PLIST.suid.h=	yes
SPECIAL_PERMS=	bin/libgtop_server2 ${REAL_ROOT_USER} sys 2755
.else
PLIST.server=	yes
PLIST.suid.h=	yes
.endif

PLIST_VARS+=    glibtop_private.h
.if ${OPSYS} == "SunOS" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
PLIST.glibtop_private.h= yes
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

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
