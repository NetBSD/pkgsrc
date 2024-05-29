# $NetBSD: Makefile,v 1.122 2024/05/29 16:32:29 adam Exp $

DISTNAME=	glusterfs-10.4
PKGREVISION=	4
CATEGORIES=	filesystems
MASTER_SITES=	https://bits.gluster.org/pub/gluster/glusterfs/src/

MAINTAINER=	als@thangorodrim.ch
HOMEPAGE=	https://www.gluster.org/
COMMENT=	Cluster filesystem
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	flex bison pkg-config bash:run autoconf autoreconf automake

CONFIGURE_ARGS+=	--disable-fusermount
CONFIGURE_ARGS+=	--disable-fuse-notifications
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--without-tcmalloc
# libtirpc not in pkgsrc (yet)
CONFIGURE_ARGS+=	--without-libtirpc
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/examples/${PKGBASE}

# Upstream glusterfs effectively dropped support for 32bit platforms
# somewhere between 8.2 (works on e.g. NetBSD/i386) and 10.3 as various
# internal bits went from 32 to 64 bits and atomic updates were done
# on those - can't do that for 64bit values on a 32bit arch.
# https://github.com/gluster/glusterfs/issues/702 proposed an explicit
# drop of 32bit and eventually it just happened. See
# https://github.com/gluster/glusterfs/issues/3911#issuecomment-1451711686
# for a more detailed explanation.
BROKEN_ON_PLATFORM=	${LP32PLATFORMS}

# Make sure we do not attept to link with -lfl
# Only libfl.a is available, and libtool wants libfl.so
MAKE_FLAGS+=		LEXLIB=""

REPLACE_PYTHON+=	events/src/glustereventsd.py
REPLACE_PYTHON+=	events/src/peer_eventsapi.py
REPLACE_PYTHON+=	events/tools/eventsdash.py
REPLACE_PYTHON+=	extras/ganesha/scripts/generate-epoch.py
REPLACE_PYTHON+=	extras/geo-rep/schedule_georep.py.in
REPLACE_PYTHON+=	extras/snap_scheduler/gcron.py
REPLACE_PYTHON+=	extras/snap_scheduler/snap_scheduler.py
REPLACE_PYTHON+=	geo-replication/src/peer_georep-sshkey.py.in
REPLACE_PYTHON+=	geo-replication/src/peer_mountbroker.in
REPLACE_PYTHON+=	geo-replication/src/peer_mountbroker.py.in
REPLACE_PYTHON+=	geo-replication/syncdaemon/gsyncd.py
REPLACE_PYTHON+=	geo-replication/syncdaemon/gsyncdstatus.py
REPLACE_PYTHON+=	tools/gfind_missing_files/gfid_to_path.py
REPLACE_PYTHON+=	tools/glusterfind/S57glusterfind-delete-post.py
REPLACE_PYTHON+=	tools/glusterfind/glusterfind.in
REPLACE_PYTHON+=	tools/glusterfind/src/brickfind.py
REPLACE_PYTHON+=	tools/glusterfind/src/changelog.py
REPLACE_PYTHON+=	tools/glusterfind/src/main.py
REPLACE_PYTHON+=	tools/glusterfind/src/nodeagent.py

REPLACE_BASH+=		extras/ganesha/ocf/ganesha_grace
REPLACE_BASH+=		extras/ganesha/ocf/ganesha_mon
REPLACE_BASH+=		extras/ganesha/ocf/ganesha_nfsd
REPLACE_BASH+=		extras/ganesha/scripts/create-export-ganesha.sh
REPLACE_BASH+=		extras/ganesha/scripts/dbus-send.sh
REPLACE_BASH+=		extras/ganesha/scripts/ganesha-ha.sh
REPLACE_BASH+=		extras/geo-rep/generate-gfid-file.sh
REPLACE_BASH+=		extras/geo-rep/get-gfid.sh
REPLACE_BASH+=		extras/geo-rep/gsync-upgrade.sh
REPLACE_BASH+=		extras/geo-rep/secondary-upgrade.sh
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
SUBST_FILES.mtab+=	xlators/mount/fuse/utils/mount.glusterfs.in
SUBST_SED.mtab+=	-e "s,mtab,/proc/mounts,g"

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	pre-build
SUBST_FILES.etc=	libglusterfs/src/logging.c
SUBST_FILES.etc+=	doc/glusterfsd.8
SUBST_SED.etc=		-e "s,/etc/gluster,${PREFIX}/etc/gluster,g"

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	pre-configure
SUBST_FILES.bash=	build-aux/pkg-version
SUBST_SED.bash=		-e "s,/bin/bash,${BASH},g"

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=	${EGDIR}/eventsconfig.json ${PKG_SYSCONFDIR}/glusterfs/eventsconfig.json
CONF_FILES+=	${EGDIR}/ganesha/ganesha-ha.conf.sample ${PKG_SYSCONFDIR}/glusterfs/ganesha/ganesha-ha.conf.sample
CONF_FILES+=	${EGDIR}/gluster-rsyslog-5.8.conf ${PKG_SYSCONFDIR}/glusterfs/gluster-rsyslog-5.8.conf
CONF_FILES+=	${EGDIR}/gluster-rsyslog-7.2.conf ${PKG_SYSCONFDIR}/glusterfs/gluster-rsyslog-7.2.conf
CONF_FILES+=	${EGDIR}/glusterd.vol ${PKG_SYSCONFDIR}/glusterfs/glusterd.vol
CONF_FILES+=	${EGDIR}/glusterfs-georep-logrotate ${PKG_SYSCONFDIR}/glusterfs/glusterfs-georep-logrotate
CONF_FILES+=	${EGDIR}/glusterfs-logrotate ${PKG_SYSCONFDIR}/glusterfs/glusterfs-logrotate
CONF_FILES+=	${EGDIR}/group-db-workload ${PKG_SYSCONFDIR}/glusterfs/group-db-workload
CONF_FILES+=	${EGDIR}/group-distributed-virt ${PKG_SYSCONFDIR}/glusterfs/group-distributed-virt
CONF_FILES+=	${EGDIR}/group-gluster-block ${PKG_SYSCONFDIR}/glusterfs/group-gluster-block
CONF_FILES+=	${EGDIR}/group-metadata-cache ${PKG_SYSCONFDIR}/glusterfs/group-metadata-cache
CONF_FILES+=	${EGDIR}/group-nl-cache ${PKG_SYSCONFDIR}/glusterfs/group-nl-cache
CONF_FILES+=	${EGDIR}/group-samba ${PKG_SYSCONFDIR}/glusterfs/group-samba
CONF_FILES+=	${EGDIR}/group-virt.example ${PKG_SYSCONFDIR}/glusterfs/group-virt.example
CONF_FILES+=	${EGDIR}/logger.conf.example ${PKG_SYSCONFDIR}/glusterfs/logger.conf.example
CONF_FILES+=	${EGDIR}/thin-arbiter.vol ${PKG_SYSCONFDIR}/glusterfs/thin-arbiter.vol
OWN_DIRS+=	${PKG_SYSCONFDIR}/glusterfs
OWN_DIRS+=	${PKG_SYSCONFDIR}/glusterfs/ganesha

OWN_DIRS+=		${VARBASE}/log/glusterfs
BUILD_DEFS+=		VARBASE

RCD_SCRIPTS=		glusterd

PLIST_SRC=		${PLIST_SRC_DFLT}
PLIST_SUBST+=		VARBASE=${VARBASE}
PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}
PLIST_SUBST+=		GLUSTERFS_VERSION=${DISTNAME:S/glusterfs-//}
MESSAGE_SRC=		${PKGDIR}/MESSAGE.${OPSYS}

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

pre-build:
	cd ${WRKSRC}/extras && 					\
	${ECHO} "glusterd.vol.sample: glusterd.vol" >> Makefile &&	\
	${ECHO} "	cp glusterd.vol glusterd.vol.sample" >> Makefile

# Debug
#CFLAGS+=		-g
#INSTALL_UNSTRIPPED=	yes
#CONFIGURE_ARGS+=	--enable-debug
#.include "../../devel/boehm-gc/buildlink3.mk"
#CFLAGS+=		-DGC_DEBUG
#CFLAGS+=		-include gc.h
#LIBS+=			-lgc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
post-install:
	${INSTALL_SCRIPT} ${DESTDIR}/sbin/mount.glusterfs \
	    ${DESTDIR}/${PREFIX}/sbin/mount.glusterfs
.else
post-install:
	${INSTALL_SCRIPT} ${DESTDIR}/sbin/mount_glusterfs \
	    ${DESTDIR}/${PREFIX}/sbin/mount_glusterfs
.endif

.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/argp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.userspace-rcu+=	userspace-rcu>=0.12.1
.include "../../devel/userspace-rcu/buildlink3.mk"
.if ${OPSYS} == "Linux"
.include "../../devel/liburing/buildlink3.mk"
.include "../../sysutils/acl/buildlink3.mk"
.endif
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && exists(/usr/include/execinfo.h)
LIBS+=	-lexecinfo
.endif

.include "../../mk/bsd.pkg.mk"
