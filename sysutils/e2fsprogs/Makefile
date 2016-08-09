# $NetBSD: Makefile,v 1.22 2016/08/09 21:46:06 jdolecek Exp $

DISTNAME=	e2fsprogs-1.43.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=e2fsprogs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://e2fsprogs.sourceforge.net/
COMMENT=	Second extended file system (ext2fs) management programs
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2 AND modified-bsd AND mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	makeinfo gmake
INFO_FILES=	yes

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

# Only build fsck(8) on platforms that need it.
PLIST_VARS+=		fsck
.if ${OPSYS} == "Linux"
PLIST.fsck=		yes
.else
CONFIGURE_ARGS+=	--disable-fsck
.endif

EGDIR=			${PREFIX}/share/examples/ext2fs
CONF_FILES+=		${EGDIR}/mke2fs.conf ${PKG_SYSCONFDIR}/mke2fs.conf
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} root_sysconfdir=${EGDIR:Q}

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	Give correct path for man page
SUBST_STAGE.man=	post-patch

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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
