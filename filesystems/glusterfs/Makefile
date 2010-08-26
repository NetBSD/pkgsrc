# $NetBSD: Makefile,v 1.1.1.1 2010/08/26 14:26:18 manu Exp $
#

DISTNAME=	glusterfs-3.0.5
CATEGORIES=	filesystems
MASTER_SITES=	http://ftp.gluster.com/pub/gluster/glusterfs/3.0/LATEST/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gluster.org/glusterfs.php
COMMENT=	Cluster filesystem
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PYTHON_VERSIONS_ACCEPTED= 26 25
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

SUBST_CLASSES+=		py
SUBST_STAGE.py=		post-build
SUBST_FILES.py=		extras/volgen/glusterfs-volgen
SUBST_SED.py=		-e "s,/usr/bin/python,${PYTHONBIN},g"

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	post-build
SUBST_FILES.bash=	xlators/mount/fuse/utils/mount.glusterfs
SUBST_SED.bash=		-e "s,/bin/bash,/bin/sh,g"


REPLACE_PYTHON+=	${WRKSRC}/extras/volgen/glusterfs-volgen

EGDIR=			${PREFIX}/etc/glusterfs
CONF_FILES+=		${EGDIR}/glusterfs.vol.sample ${EGDIR}/glusterfs.vol
CONF_FILES+=		${EGDIR}/glusterfsd.vol.sample ${EGDIR}/glusterfsd.vol
OWN_DIRS+=		${VARBASE}/glusterfs
BUILD_DEFS+=		VARBASE

post-install:
	cp ${DESTDIR}/sbin/mount.glusterfs ${DESTDIR}/${PREFIX}/sbin/

.include "../../mk/bsd.prefs.mk"
.include "../../lang/python/application.mk"
.include "../../devel/flex/buildlink3.mk"
.if ${OPSYS} == "NetBSD"
.include "../../filesystems/perfuse/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
