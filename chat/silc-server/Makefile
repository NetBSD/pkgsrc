# $NetBSD: Makefile,v 1.40 2005/06/19 01:22:17 salo Exp $
#

DISTNAME=		silc-server-1.0
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

USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
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

OWN_DIRS_PERMS+=	${VARBASE}/log/silcd ${SILCD_USER} ${SILCD_GROUP} 0700

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/${PKGBASE}
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/${PKGBASE}
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-silcd-config-file=${PKG_SYSCONFDIR}/silcd.conf
CONFIGURE_ARGS+=	--with-simdir=${PREFIX}/lib/${PKGBASE}/modules
CONFIGURE_ARGS+=	--with-logsdir=${VARBASE}/log/silcd
CONFIGURE_ARGS+=	--with-silcd-pid-file=${VARBASE}/run/silcd.pid
CONFIGURE_ARGS+=	--without-iconv
CONFIGURE_ARGS+=	--without-libtoolfix
CONFIGURE_ARGS+=	--enable-shared

# XXX: Avoid an ICE in gcc2 on sparc64
#
CONFIGURE_ENV+=		F77=${FALSE}

.if ${MACHINE_ARCH} != "i386"
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "options.mk"

post-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/motd.txt \
		> ${EGDIR}/motd.txt.default

.include "../../mk/bsd.pkg.mk"
