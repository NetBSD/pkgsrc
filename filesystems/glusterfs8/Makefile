# $NetBSD: Makefile,v 1.6 2024/05/29 16:32:29 adam Exp $

DISTNAME=	glusterfs-8.2
PKGREVISION=	13
CATEGORIES=	filesystems
MASTER_SITES=	http://bits.gluster.org/pub/gluster/glusterfs/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gluster.org/
COMMENT=	Cluster filesystem
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		flex bison pkg-config bash

CONFIGURE_ARGS+=	--disable-fusermount
CONFIGURE_ARGS+=	--disable-fuse-notifications
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

# Make sure we do not attept to link with -lfl
# Only libfl.a is available, and libtool wants libfl.so
MAKE_FLAGS+=		LEXLIB=""

REPLACE_PYTHON+=	contrib/ipaddr-py/ipaddr.py
REPLACE_PYTHON+=	events/src/glustereventsd.py
REPLACE_PYTHON+=	events/src/peer_eventsapi.py
REPLACE_PYTHON+=	events/tools/eventsdash.py
REPLACE_PYTHON+=	extras/ganesha/scripts/generate-epoch.py
REPLACE_PYTHON+=	extras/geo-rep/schedule_georep.py.in
REPLACE_PYTHON+=	extras/snap_scheduler/gcron.py
REPLACE_PYTHON+=	extras/snap_scheduler/snap_scheduler.py
REPLACE_PYTHON+=	geo-replication/src/peer_georep-sshkey.py.in
REPLACE_PYTHON+=	geo-replication/src/peer_mountbroker.in
REPLACE_PYTHON+=	geo-replication/src/peer_mountbroker.py
REPLACE_PYTHON+=	geo-replication/src/peer_mountbroker.py.in
REPLACE_PYTHON+=	geo-replication/syncdaemon/changelogagent.py
REPLACE_PYTHON+=	geo-replication/syncdaemon/gsyncd.py
REPLACE_PYTHON+=	geo-replication/syncdaemon/gsyncdstatus.py
REPLACE_PYTHON+=	tools/gfind_missing_files/gfid_to_path.py
REPLACE_PYTHON+=	tools/glusterfind/S57glusterfind-delete-post.py
REPLACE_PYTHON+=	tools/glusterfind/glusterfind.in
REPLACE_PYTHON+=	tools/glusterfind/src/__init__.py
REPLACE_PYTHON+=	tools/glusterfind/src/brickfind.py
REPLACE_PYTHON+=	tools/glusterfind/src/changelog.py
REPLACE_PYTHON+=	tools/glusterfind/src/changelogdata.py
REPLACE_PYTHON+=	tools/glusterfind/src/conf.py
REPLACE_PYTHON+=	tools/glusterfind/src/libgfchangelog.py
REPLACE_PYTHON+=	tools/glusterfind/src/main.py
REPLACE_PYTHON+=	tools/glusterfind/src/nodeagent.py
REPLACE_PYTHON+=	tools/glusterfind/src/utils.py

REPLACE_BASH+=		extras/ganesha/ocf/ganesha_grace
REPLACE_BASH+=		extras/ganesha/ocf/ganesha_mon
REPLACE_BASH+=		extras/ganesha/ocf/ganesha_nfsd
REPLACE_BASH+=		extras/ganesha/scripts/copy-export-ganesha.sh
REPLACE_BASH+=		extras/ganesha/scripts/create-export-ganesha.sh
REPLACE_BASH+=		extras/ganesha/scripts/dbus-send.sh
REPLACE_BASH+=		extras/ganesha/scripts/ganesha-ha.sh
REPLACE_BASH+=		extras/geo-rep/generate-gfid-file.sh
REPLACE_BASH+=		extras/geo-rep/get-gfid.sh
REPLACE_BASH+=		extras/geo-rep/gsync-upgrade.sh
REPLACE_BASH+=		extras/geo-rep/slave-upgrade.sh
REPLACE_BASH+=		extras/peer_add_secret_pub.in
REPLACE_BASH+=		extras/post-upgrade-script-for-quota.sh
REPLACE_BASH+=		extras/pre-upgrade-script-for-quota.sh
REPLACE_BASH+=		extras/stop-all-gluster-processes.sh
REPLACE_BASH+=		extras/thin-arbiter/setup-thin-arbiter.sh
REPLACE_BASH+=		geo-replication/src/gverify.sh
REPLACE_BASH+=		geo-replication/src/peer_gsec_create.in
REPLACE_BASH+=		geo-replication/src/set_geo_rep_pem_keys.sh

# Explicit substitution of bash
CHECK_PORTABILITY_SKIP+=	extras/peer_add_secret_pub.in


SUBST_CLASSES+=		mtab
SUBST_STAGE.mtab=	post-build
SUBST_FILES.mtab=	doc/mount.glusterfs.8
SUBST_FILES.mtab=	libglusterfs/src/compat.h
SUBST_FILES.mtab=	xlators/mount/fuse/utils/mount.glusterfs.in
SUBST_SED.mtab=		-e "s,mtab,/proc/mounts,g"

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	pre-build
SUBST_FILES.etc+=	libglusterfs/src/logging.c
SUBST_FILES.etc+=	doc/glusterfsd.8
SUBST_SED.etc=		-e "s,/etc/gluster,${PREFIX}/etc/gluster,g"

#EGDIR=			${PREFIX}/etc/glusterfs
#CONF_FILES+=		${EGDIR}/glusterd.vol.sample ${EGDIR}/glusterd.vol
OWN_DIRS+=		${VARBASE}/log/glusterfs
BUILD_DEFS+=		VARBASE

RCD_SCRIPTS=		glusterd

PLIST_SRC=		${PLIST_SRC_DFLT}
PLIST_SUBST+=		VARBASE=${VARBASE}
PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}
PLIST_SUBST+=		GLUSTERFS_VERSION=${DISTNAME:S/glusterfs-//}
MESSAGE_SRC=		${PKGDIR}/MESSAGE.${OPSYS}

pre-build:
	cd ${WRKSRC}/extras && 					\
	${ECHO} "glusterd.vol.sample: glusterd.vol" >> Makefile &&	\
	${ECHO} "	cp glusterd.vol glusterd.vol.sample" >> Makefile

post-install:
	${INSTALL_SCRIPT} ${DESTDIR}/sbin/mount_glusterfs \
	    ${DESTDIR}/${PREFIX}/sbin/mount_glusterfs

# Debug
CFLAGS+=		-g 
INSTALL_UNSTRIPPED=	yes
CONFIGURE_ARGS+=	--enable-debug
#.include "../../devel/boehm-gc/buildlink3.mk"
#CFLAGS+=		-DGC_DEBUG
#CFLAGS+=		-include gc.h
#LIBS+=			-lgc

.include "../../mk/bsd.prefs.mk"

.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/argp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.userspace-rcu+=	userspace-rcu>=0.12.1
.include "../../devel/userspace-rcu/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && exists(/usr/include/execinfo.h)
LIBS+=	-lexecinfo
.endif

.include "../../mk/bsd.pkg.mk"
