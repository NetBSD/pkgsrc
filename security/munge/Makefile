# $NetBSD: Makefile,v 1.30 2024/05/18 22:31:05 bacon Exp $

DISTNAME=	munge-0.5.16
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=dun/}
GITHUB_RELEASE=	${DISTNAME}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://dun.github.io/munge/
COMMENT=	Authentication service for creating and validating credentials
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		perl pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--disable-silent-rules

.include "../../mk/bsd.prefs.mk"

MUNGE_DIR?=		${PREFIX}/var/lib/munge
MUNGE_LOG_DIR?=		${PREFIX}/var/log/munge
MUNGE_RUN_DIR?=		${PREFIX}/var/run/munge
MUNGE_ETC_DIR?=		${PREFIX}/etc/munge
MUNGE_USER=		munge
MUNGE_GROUP=		${MUNGE_USER}

PKG_GROUPS+=		${MUNGE_GROUP}
PKG_USERS+=		${MUNGE_USER}:${MUNGE_GROUP}
PKG_GECOS.munge=	Munge user
PKG_HOME.munge=		${MUNGE_DIR}

OWN_DIRS_PERMS+=	${MUNGE_DIR} ${MUNGE_USER} ${MUNGE_GROUP} 0700
OWN_DIRS_PERMS+=	${MUNGE_LOG_DIR} ${MUNGE_USER} ${MUNGE_GROUP} 0700
OWN_DIRS_PERMS+=	${MUNGE_RUN_DIR} ${MUNGE_USER} ${MUNGE_GROUP} 0755
OWN_DIRS_PERMS+=	${MUNGE_ETC_DIR} ${MUNGE_USER} ${MUNGE_GROUP} 0700

RCD_SCRIPTS=		munge
PKG_RCD_SCRIPTS=	yes

.if ${OPSYS} == Linux
EGDIR=			${PREFIX}/share/examples/munge
PKG_SYSCONFSUBDIR=	sysconfig
CONF_FILES=		${EGDIR}/systemd.sysconfig ${PKG_SYSCONFDIR}/munge
CONF_FILES+=		${EGDIR}/logrotate.conf ${PREFIX}/etc/logrotate.d/munge

INSTALLATION_DIRS+=	${EGDIR} etc/logrotate.d
CONFIGURE_ARGS+=	--with-sysconfigdir=${PKG_SYSCONFDIR}
AUTO_MKDIRS=		yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/logrotate.d/munge \
		${DESTDIR}${PREFIX}/share/examples/munge/logrotate.conf
	${MV} ${DESTDIR}${PREFIX}/etc/sysconfig/munge \
		${DESTDIR}${PREFIX}/share/examples/munge/systemd.sysconfig
.endif

.if ${OPSYS} == Darwin
# Should not be necessary with AUTO_MKDIRS enabled, but it is
INSTALLATION_DIRS+=	share/munge/Launchd
post-install:
	# ${MKDIR} ${DESTDIR}${PREFIX}/share/munge/Launchd
	${INSTALL_DATA} ${FILESDIR}/*.plist \
		${DESTDIR}${PREFIX}/share/munge/Launchd
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
