# $NetBSD: Makefile,v 1.1.1.1 2001/11/30 23:33:34 hubertf Exp $

DISTNAME=		silc-server-0.6.4
CATEGORIES=		chat
MASTER_SITES=		http://ftp.silcnet.org/server/sources/ \
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
USE_NCURSES=		yes
USE_LIBTOOL=		yes
USE_BUILDLINK_ONLY=	yes

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	silcd

CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/silcd \
			--with-etcdir=${PKG_SYSCONFBASE}/${PKG_SYSCONFSUBDIR} \
			--with-silcd-config-file=${PKG_SYSCONFBASE}/${PKG_SYSCONFSUBDIR}/silcd.conf \
			--with-silcd-pid-file=/var/run/silcd.pid \
			--with-logsdir=/var/log/silcd

INSTALL_FILE=		${WRKDIR}/INSTALL
DEINSTALL_FILE=		${WRKDIR}/DEINSTALL

FILES_SUBST+=		PREFIX=${PREFIX}
FILES_SUBST+=		CAT=${CAT:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CHOWN=${CHOWN:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		MKDIR=${MKDIR:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST+=		RMDIR=${RMDIR:Q}
FILES_SUBST+=		TRUE=${TRUE:Q}
FILES_SUBST+=		SILCD_CONF_DIR=${PKG_SYSCONFBASE}/${PKG_SYSCONFSUBDIR}
FILES_SUBST+=		CONF_DIR=${PKG_SYSCONFBASE}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/-e s!@/}

post-build:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/silcd.sh > ${WRKDIR}/silcd.sh

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL
	${INSTALL_SCRIPT} ${WRKDIR}/silcd.sh ${PKG_SYSCONFBASE}/rc.d/silcd

.if (${MACHINE_ARCH} != "i386")
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "../../devel/glib/buildlink.mk"
.include "../../devel/pth/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
