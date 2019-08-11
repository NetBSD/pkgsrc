# $NetBSD: Makefile,v 1.78 2019/08/11 13:23:02 wiz Exp $

PKGNAME=		amanda-common-${AMANDA_VERSION}
PKGREVISION=		2

COMMENT=		Common libraries and binaries for Amanda

# genversion.c:37:10: fatal error: 'genversion.h' file not found
MAKE_JOBS_SAFE=		no

.include "../../sysutils/amanda-common/Makefile.common"

CPPFLAGS.SunOS+=	-D_LARGEFILE64_SOURCE
LDFLAGS.SunOS+=		-lsocket

CONFIGURE_ARGS+=	--without-server --without-client --without-gnuplot

PKG_GROUPS=		${AMANDA_GROUP}
PKG_USERS=		${AMANDA_USER}:${AMANDA_GROUP}

PKG_GECOS.${AMANDA_USER}=	Amanda backup user
PKG_SHELL.${AMANDA_USER}=	${SH}
PKG_HOME.${AMANDA_USER}=	${AMANDA_VAR}

OWN_DIRS+=		${PKG_SYSCONFDIR}/amanda
OWN_DIRS_PERMS=		${AMANDA_VAR} ${AMANDA_USER} ${AMANDA_GROUP} 0750
OWN_DIRS_PERMS+=	${AMANDA_VAR}/gnutar-lists ${AMANDA_USER} ${AMANDA_GROUP} 0750
OWN_DIRS_PERMS+=	${VARBASE}/log/amanda ${AMANDA_USER} ${AMANDA_GROUP} 0750

CONF_FILES_PERMS=	${PREFIX}/share/doc/amanda/example/amanda-client.conf \
			${PKG_SYSCONFDIR}/amanda/amanda-client.conf     \
			${AMANDA_USER} ${AMANDA_GROUP} 0600
CONF_FILES_PERMS=	${PREFIX}/share/doc/amanda/example/amanda-security.conf \
			${PKG_SYSCONFDIR}/amanda/amanda-security.conf     \
			${AMANDA_USER} ${AMANDA_GROUP} 0600

REQD_FILES_PERMS+=	/dev/null ${AMANDA_VAR}/amandates ${AMANDA_USER} ${AMANDA_GROUP} 0640

SPECIAL_PERMS+=		sbin/amservice ${AM_PROG_PERMS}

.include "../../mk/bsd.pkg.mk"
