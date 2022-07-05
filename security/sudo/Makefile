# $NetBSD: Makefile,v 1.190 2022/07/05 11:01:38 adam Exp $

DISTNAME=	sudo-1.9.11p3
CATEGORIES=	security
MASTER_SITES=	https://www.sudo.ws/dist/
MASTER_SITES+=	ftp://ftp.sudo.ws/pub/sudo/
MASTER_SITES+=	ftp://ftp.uwsg.indiana.edu/pub/security/sudo/
MASTER_SITES+=	http://ftp.twaren.net/Unix/Security/Sudo/
MASTER_SITES+=	http://ftp.tux.org/pub/security/sudo/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sudo.ws/
COMMENT=	Allow others to run commands as root
LICENSE=	isc AND modified-bsd

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-intercept
CONFIGURE_ARGS+=	--disable-path-info
CONFIGURE_ARGS+=	--disable-root-mailer
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-exampledir=${PREFIX}/${EGDIR}
CONFIGURE_ARGS+=	--with-ignore-dot
CONFIGURE_ARGS+=	--with-nbsdops
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/lib # for a bunch of shared libs
CONFIGURE_ARGS+=	--with-rundir=${VARBASE}/run/sudo
CONFIGURE_ARGS+=	--with-logpath=${VARBASE}/log/sudo.log
# to always install man instead of cat
CONFIGURE_ENV+=		NROFFPROG=${CAT:Q}
CONFIGURE_ENV+=		mansectsu=8
CONFIGURE_ENV+=		mansectform=5
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		noexec
.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--with-noexec=no
CONFIGURE_ENV+=		ax_cv_check_cflags___static_libgcc=no
.else
PLIST.noexec=		yes
.endif

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} > 070000
CFLAGS+=	-D_OPENBSD_SOURCE=1
.endif
.if !empty(MACHINE_PLATFORM:MNetBSD-[5-6].*-*)
CFLAGS+=	-D_INCOMPLETE_XOPEN_C063=1
.endif

.include "options.mk"

OWN_DIRS+=		${VARBASE}/run
BUILD_DEFS+=		VARBASE

EGDIR=			share/examples/${PKGBASE}
CONF_FILES_PERMS=	${EGDIR}/sudo.conf ${PKG_SYSCONFDIR}/sudo.conf \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${EGDIR}/sudo_logsrvd.conf \
			${PKG_SYSCONFDIR}/sudo_logsrvd.conf \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0440
CONF_FILES_PERMS+=	${EGDIR}/sudoers ${PKG_SYSCONFDIR}/sudoers \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0440
OWN_DIRS+=		${PKG_SYSCONFDIR}/sudoers.d
SPECIAL_PERMS+=		bin/sudo ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=		bin/sudoreplay ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 511

INSTALLATION_DIRS+=	${EGDIR}
NOT_FOR_UNPRIVILEGED=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/plugins/sudoers/sudoers ${DESTDIR}${PREFIX}/${EGDIR}/sudoers

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
