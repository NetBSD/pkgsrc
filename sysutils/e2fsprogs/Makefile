# $NetBSD: Makefile,v 1.36 2022/12/13 10:55:03 jperkin Exp $

DISTNAME=	e2fsprogs-1.46.4
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://www.kernel.org/pub/linux/kernel/people/tytso/e2fsprogs/v${PKGVERSION_NOREV}/
#MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=e2fsprogs/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://e2fsprogs.sourceforge.net/
COMMENT=	Second extended file system (ext2fs) management programs
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND modified-bsd AND mit

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake makeinfo pkg-config
GNU_CONFIGURE=		yes
# Use external libraries
CONFIGURE_ARGS+=	--disable-libblkid
CONFIGURE_ARGS+=	--disable-libuuid
# This does not build on NetBSD due to missing FUSE_MAKE_VERSION in fuse.h,
# but will be automatically built on certain systems when libfuse can be found
# by the configure script without fuse.buildlink3.mk being included, resulting
# in PLIST conflicts.
#
# I'm unsure whether this is better or more useful than filesystems/fuse-ext2.
CONFIGURE_ARGS+=	--disable-fuse2fs
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
INFO_FILES=		yes
INSTALL_TARGET=		install install-libs

PKGCONFIG_OVERRIDE+=	lib/blkid/blkid.pc.in
PKGCONFIG_OVERRIDE+=	lib/e2p/e2p.pc.in
PKGCONFIG_OVERRIDE+=	lib/et/com_err.pc.in
PKGCONFIG_OVERRIDE+=	lib/ext2fs/ext2fs.pc.in
PKGCONFIG_OVERRIDE+=	lib/ss/ss.pc.in

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
BUILDLINK_TRANSFORM+=	rm:-luuid
.endif

.include "options.mk"

PLIST_VARS+=		shlib
.if ${OBJECT_FMT} == "ELF"
PLIST.shlib=		yes
CONFIGURE_ARGS+=	--enable-elf-shlibs
.else
CONFIGURE_ARGS+=	--disable-elf-shlibs
.endif

# Only build fsck(8) on platforms that need it.
PLIST_VARS+=		fsck
.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-fsck
PLIST.fsck=		yes
.else
CONFIGURE_ARGS+=	--disable-fsck
.endif

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-rpath-link,../../lib
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-rpath-link,../lib

EGDIR=			${PREFIX}/share/examples/ext2fs
CONF_FILES+=		${EGDIR}/mke2fs.conf ${PKG_SYSCONFDIR}/mke2fs.conf
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} root_sysconfdir=${EGDIR}

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	Give correct path for man page
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man+=	misc/mke2fs.8.in
SUBST_FILES.man+=	misc/mke2fs.conf.5.in
SUBST_FILES.man+=	e2fsck/e2fsck.conf.5.in
SUBST_FILES.man+=	lib/blkid/libblkid.3.in
SUBST_FILES.man+=	misc/blkid.8.in
SUBST_SED.man+=		-e '/mke2fs.conf/s,/etc,@root_sysconfdir@,'
SUBST_SED.man+=		-e '/mke2fs.conf/s,/etc,@root_sysconfdir@,'
# next (two) path's in the man page do not exist
SUBST_SED.man+=		-e '/e2fsck.conf/s,/etc,@root_sysconfdir@,'
SUBST_SED.man+=		-e   '/blkid.tab/s,/etc,@root_sysconfdir@,'

.if ${OPSYS} == "Linux"
USE_TOOLS+=		bash:run
REPLACE_BASH+=		scrub/e2scrub.in
REPLACE_BASH+=		scrub/e2scrub_all.in
.endif

.include "../../devel/libblkid/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
