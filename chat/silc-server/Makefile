# $NetBSD: Makefile,v 1.5 2002/01/26 14:43:16 hubertf Exp $

DISTNAME=		silc-server-0.7.6
CATEGORIES=		chat
MASTER_SITES=		http://silcnet.org/download/server/sources/ \
			ftp://ftp.silcnet.org/silc/server/sources/ \
			http://www.planetmirror.com/pub/silcnet/server/sources/ \
			ftp://ftp.au.silcnet.org/pub/silcnet/server/sources/ \
			http://munitions.vipul.net/software/mirrors/silc/server/sources/ \
			ftp://ftp.no.silcnet.org/pub/silc/server/sources/ \
			http://the.wiretapped.net/security/network-security/silc/server/sources/ \
			ftp://ftp.wiretapped.net/pub/security/network-security/silc/server/sources/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		salo@silcnet.org
HOMEPAGE=		http://www.silcnet.org/
COMMENT=                Server for the Secure Internet Live Conferencing (SILC) protocol

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_BUILDLINK_ONLY=	yes

.include "../../mk/bsd.prefs.mk"

SILCD_USER?=		silcd
SILCD_GROUP?=		silcd
PKG_GROUPS=		${SILCD_GROUP}
PKG_USERS=		${SILCD_USER}:${SILCD_GROUP}::SILC\\ Server\\ user

PKG_SYSCONFSUBDIR?=	silcd

CONF_FILES_MODE=	0600
CONF_FILES=		${PREFIX}/share/doc/silcd/silcd.conf.default \
			${PKG_SYSCONFDIR}/silcd.conf
CONF_FILES_PERMS=	${PREFIX}/share/doc/silcd/motd.txt.default \
			${PKG_SYSCONFDIR}/motd.txt \
			${ROOT_USER} ${ROOT_GROUP} 0644
SUPPORT_FILES_PERMS=	${PREFIX}/share/doc/silcd/silcd.default \
			${PREFIX}/etc/rc.d/silcd \
			${ROOT_USER} ${ROOT_GROUP} 0555

RCD_SCRIPTS=		silcd
RCD_SCRIPTS_MODE=	0555

OWN_DIRS_PERMS+=	/var/log/silcd ${SILCD_USER} ${SILCD_GROUP} 0700

INSTALL_EXTRA_TMPL=	${PKGDIR}/INSTALL
DEINSTALL_EXTRA_TMPL=	${PKGDIR}/DEINSTALL

CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/silcd
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-silcd-config-file=${PKG_SYSCONFDIR}/silcd.conf
CONFIGURE_ARGS+=	--with-silcd-pid-file=/var/run/silcd.pid
CONFIGURE_ARGS+=	--with-logsdir=/var/log/silcd
CONFIGURE_ARGS+=	--without-ncurses

.if (${MACHINE_ARCH} != "i386")
CONFIGURE_ARGS+=	--disable-asm
.endif

post-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/silcd.sh \
		> ${PREFIX}/share/doc/silcd/silcd.default
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/motd.txt \
		> ${PREFIX}/share/doc/silcd/motd.txt.default

.include "../../devel/glib/buildlink.mk"
.include "../../devel/pth/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
