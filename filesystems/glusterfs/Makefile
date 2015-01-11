# $NetBSD: Makefile,v 1.47 2015/01/11 23:07:01 joerg Exp $

DISTNAME=	glusterfs-3.6.0
#PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	http://bits.gluster.org/pub/gluster/glusterfs/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gluster.org/
COMMENT=	Cluster filesystem
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		flex bison

CONFIGURE_ARGS+=	--disable-fusermount
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

# Make sure we do not attept to link with -lfl
# Only libfl.a is available, and libtool wants libfl.so
MAKE_FLAGS+=		LEXLIB=""
MAKE_FLAGS+=		libglusterfs_la_LIBADD=""

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # only 2.x supported as of 3.6.0

#REPLACE_PYTHON+=	contrib/ipaddr-py/ipaddr.py
#REPLACE_PYTHON+=	gen-headers.py
#REPLACE_PYTHON+=	tests/bugs/overlap.py
#REPLACE_PYTHON+=	tests/utils/create-files.py
REPLACE_PYTHON+=	geo-replication/syncdaemon/changelogagent.py
REPLACE_PYTHON+=	geo-replication/syncdaemon/gsyncd.py
REPLACE_PYTHON+=	contrib/ipaddr-py/ipaddr.py

REPLACE_BASH+=		extras/geo-rep/generate-gfid-file.sh
REPLACE_BASH+=		extras/geo-rep/get-gfid.sh
REPLACE_BASH+=		extras/post-upgrade-script-for-quota.sh
REPLACE_BASH+=		extras/pre-upgrade-script-for-quota.sh
REPLACE_BASH+=		extras/geo-rep/slave-upgrade.sh
REPLACE_BASH+=		extras/geo-rep/gsync-upgrade.sh
REPLACE_BASH+=		geo-replication/src/gverify.sh
REPLACE_BASH+=		geo-replication/src/peer_add_secret_pub.in
REPLACE_BASH+=		geo-replication/src/peer_gsec_create.in
REPLACE_BASH+=		geo-replication/src/set_geo_rep_pem_keys.sh


SUBST_CLASSES+=		mtab
SUBST_STAGE.mtab=	post-build
SUBST_FILES.mtab=	doc/mount.glusterfs.8
SUBST_FILES.mtab=	libglusterfs/src/compat.h
SUBST_FILES.mtab=	xlators/mount/fuse/utils/mount.glusterfs.in
SUBST_SED.mtab=		-e "s,/etc/mtab,/proc/mounts,g"

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	pre-build
SUBST_FILES.etc+=       libglusterfs/src/logging.c
SUBST_FILES.etc+=       extras/ocf/volume
SUBST_FILES.etc+=       doc/glusterfsd.8
SUBST_SED.etc=		-e "s,/etc/gluster,${PREFIX}/etc/gluster,g"

SUBST_CLASSES+=		vol
SUBST_STAGE.vol=	post-build
SUBST_FILES.vol=	extras/Makefile
SUBST_SED.vol=		-e "/^vol_DATA/s/glusterd.vol/glusterd.vol.sample/g"

EGDIR=			${PREFIX}/etc/glusterfs
CONF_FILES+=		${EGDIR}/glusterd.vol.sample ${EGDIR}/glusterd.vol
OWN_DIRS+=		${VARBASE}/log/glusterfs
BUILD_DEFS+=		VARBASE

RCD_SCRIPTS=		glusterd

PLIST_SRC=		${PLIST_SRC_DFLT}
PLIST_SUBST+=		VARBASE=${VARBASE}
PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}
MESSAGE_SRC=		${PKGDIR}/MESSAGE.${OPSYS}

pre-build:
	cd ${WRKSRC}/extras && 					\
	echo "glusterd.vol.sample: glusterd.vol" >> Makefile &&	\
	echo "	cp glusterd.vol glusterd.vol.sample" >> Makefile

post-install:
	${INSTALL_SCRIPT} ${DESTDIR}/sbin/mount_glusterfs \
	    ${DESTDIR}/${PREFIX}/sbin/mount_glusterfs

# Debug
CFLAGS+=		-g
INSTALL_UNSTRIPPED=	yes
CONFIGURE_ARGS+=	--enable-debug
#.include "../../devel/boehm-gc/buildlink3.mk"
#CFLAGS+=-DGC_DEBUG
#CFLAGS+=-include gc.h
#LIBS+=-lgc

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	mmx
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PLIST.mmx=	yes
.endif

#.include "../../devel/argp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && exists(/usr/include/execinfo.h)
LIBS+=	-lexecinfo
.endif

.include "../../mk/bsd.pkg.mk"
