# $NetBSD: Makefile,v 1.35 2004/10/03 00:13:15 tv Exp $
#

DISTNAME=		silc-server-0.9.18
PKGREVISION=		2
CATEGORIES=		chat security
MASTER_SITES=		http://www.silcnet.org/download/server/sources/ \
			ftp://ftp.silcnet.org/silc/server/sources/ \
			http://www.fi.silcnet.org/download/server/sources/ \
			ftp://ftp.au.silcnet.org/pub/silcnet/server/sources/ \
			http://www.at.silcnet.org/download/server/sources/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.silcnet.org/
COMMENT=                Server for the Secure Internet Live Conferencing (SILC) protocol

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	libtool */*/*/libtool

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

.include "../../mk/bsd.prefs.mk"

SILCD_USER?=		silcd
SILCD_GROUP?=		silcd
PKG_GROUPS=		${SILCD_GROUP}
PKG_USERS=		${SILCD_USER}:${SILCD_GROUP}::SILC\\ Server\\ user

PKG_SYSCONFSUBDIR?=	${PKGBASE}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MAKE_ENV+=		examplesdir=${EGDIR}

CONF_FILES_MODE=	0600
CONF_FILES+=		${EGDIR}/silcd.conf.default \
			${PKG_SYSCONFDIR}/silcd.conf
CONF_FILES+=		${EGDIR}/silcalgs.conf.default \
			${PKG_SYSCONFDIR}/silcalgs.conf
CONF_FILES_PERMS+=	${EGDIR}/motd.txt.default ${PKG_SYSCONFDIR}/motd.txt \
			${ROOT_USER} ${ROOT_GROUP} 0644

RCD_SCRIPTS=		silcd

.if ${OPSYS} == "NetBSD"
RCD_SCRIPT_SRC.silcd=	${FILESDIR}/silcd.sh
.else
RCD_SCRIPT_SRC.silcd=	${FILESDIR}/silcd.generic
.endif

OWN_DIRS_PERMS+=	/var/log/silcd ${SILCD_USER} ${SILCD_GROUP} 0700

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/${PKGBASE}
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/${PKGBASE}
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-silcd-config-file=${PKG_SYSCONFDIR}/silcd.conf
CONFIGURE_ARGS+=	--with-simdir=${PREFIX}/lib/${PKGBASE}/modules
CONFIGURE_ARGS+=	--with-logsdir=/var/log/silcd
CONFIGURE_ARGS+=	--with-silcd-pid-file=/var/run/silcd.pid
CONFIGURE_ARGS+=	--without-iconv
CONFIGURE_ARGS+=	--without-libtoolfix

# XXX: Avoid an ICE in gcc2 on sparc64
#
CONFIGURE_ENV+=		F77=${FALSE}

BUILD_DEFS+=		USE_INET6

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.endif

# If you want to debug silc-server, uncomment the line below.
#
#CONFIGURE_ARGS+=       --enable-debug

.if ${MACHINE_ARCH} != "i386"
CONFIGURE_ARGS+=	--disable-asm
.endif

post-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/motd.txt \
		> ${EGDIR}/motd.txt.default

.include "../../mk/bsd.pkg.mk"
