# $NetBSD: Makefile,v 1.21 2008/01/09 13:13:09 ghen Exp $
#

DISTNAME=		vpnc-0.5.1
CATEGORIES=		net security
MASTER_SITES=		http://www.unix-ag.uni-kl.de/~massar/vpnc/

MAINTAINER=		hubertf@NetBSD.org,j+pkgsrc@salmi.ch
HOMEPAGE=		http://www.unix-ag.uni-kl.de/~massar/vpnc/
COMMENT=		Client for Cisco3000 VPN Concentrator

PKG_DESTDIR_SUPPORT=	user-destdir

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
	${INSTALL_PROGRAM} ${WRKSRC}/vpnc ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/cisco-decrypt ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-script ${DESTDIR}${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/vpnc.conf ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/vpnc-disconnect ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/pcf2vpnc ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vpnc.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/pcf2vpnc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/cisco-decrypt.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/vpnc

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
