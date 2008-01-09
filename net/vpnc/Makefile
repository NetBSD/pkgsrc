# $NetBSD: Makefile,v 1.20 2008/01/09 12:25:40 hubertf Exp $
#

DISTNAME=		vpnc-0.5.1
CATEGORIES=		net security
MASTER_SITES=		http://www.unix-ag.uni-kl.de/~massar/vpnc/

MAINTAINER=		hubertf@NetBSD.org,j+pkgsrc@salmi.ch
HOMEPAGE=		http://www.unix-ag.uni-kl.de/~massar/vpnc/
COMMENT=		Client for Cisco3000 VPN Concentrator

NOT_FOR_PLATFORM=	Interix-*-*

USE_TOOLS+=		gmake
USE_TOOLS+=		perl
INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8 \
			share/doc/vpnc share/examples/vpnc
OWN_DIRS=		${PKG_SYSCONFDIR}/vpnc

SUBST_CLASSES+= 	paths
SUBST_MESSAGE.paths=	fixing pathnames
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	config.c vpnc-script makeman.pl pcf2vpnc vpnc.8.template
SUBST_SED.paths=	-e 's|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.paths+=	-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.paths+=	-e 's|@PKGMANDIR@|${PKGMANDIR}|g'
SUBST_SED.paths+=	-e 's|@VARBASE@|${VARBASE}|g'
SUBST_SED.paths+=	-e 's|@PERL5@|${PERL5}|g'

EGDIR=			${PREFIX}/share/examples/vpnc
CONF_FILES+=		${EGDIR}/vpnc.conf ${PKG_SYSCONFDIR}/vpnc/vpnc.conf
CONF_FILES_PERMS+=	${EGDIR}/vpnc-script ${PKG_SYSCONFDIR}/vpnc/vpnc-script ${ROOT_USER} ${ROOT_GROUP} 755

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vpnc ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/cisco-decrypt ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-script ${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/vpnc.conf ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-disconnect ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/pcf2vpnc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vpnc.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/pcf2vpnc.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/cisco-decrypt.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/vpnc

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
