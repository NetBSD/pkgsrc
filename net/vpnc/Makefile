# $NetBSD: Makefile,v 1.44 2018/08/22 09:46:08 wiz Exp $
#

DISTNAME=		vpnc-0.5.3
PKGREVISION=		15
CATEGORIES=		net security
MASTER_SITES=		https://www.unix-ag.uni-kl.de/~massar/vpnc/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.unix-ag.uni-kl.de/~massar/vpnc/
COMMENT=		Client for Cisco3000 VPN Concentrator

NOT_FOR_PLATFORM=	Interix-*-*


USE_TOOLS+=		gmake
USE_TOOLS+=		perl
INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8 \
			share/doc/vpnc share/examples/vpnc
OWN_DIRS=		${PKG_SYSCONFDIR}/vpnc

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	fixing pathnames
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	config.c vpnc-script.in makeman.pl pcf2vpnc
SUBST_FILES.paths+=	vpnc.8.template vpnc-disconnect
SUBST_SED.paths=	-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.paths+=	-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.paths+=	-e 's|@PKGMANDIR@|${PKGMANDIR}|g'
SUBST_SED.paths+=	-e 's|@VARBASE@|${VARBASE}|g'
SUBST_SED.paths+=	-e 's|@PERL5@|${PERL5}|g'
SUBST_SED.paths+=	-e 's|@SH@|${SH}|g'


BUILD_DEFS+=		VARBASE

EGDIR=			${PREFIX}/share/examples/vpnc
CONF_FILES+=		${EGDIR}/default.conf \
			${PKG_SYSCONFDIR}/vpnc/default.conf
CONF_FILES_MODE=	0600
CONF_FILES_PERMS+=	${EGDIR}/vpnc-script \
			${PKG_SYSCONFDIR}/vpnc/vpnc-script \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
RCD_SCRIPTS=		vpnc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vpnc ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/cisco-decrypt ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-script ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/vpnc.conf ${DESTDIR}${EGDIR}/default.conf
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-disconnect ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/pcf2vpnc ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vpnc.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/pcf2vpnc.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/cisco-decrypt.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/vpnc

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

CFLAGS.SunOS=	-DLOG_PERROR=0

.if ${OPSYS} == "SunOS"
.include "../../net/solaris-tap/buildlink3.mk"
.endif

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
