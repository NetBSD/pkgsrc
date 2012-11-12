# $NetBSD: Makefile,v 1.4 2012/11/12 10:37:10 jdf Exp $
#

DISTNAME=	fscd-1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://komkon2.de/

MAINTAINER=	jdf@NetBSD.org
HOMEPAGE=	https://vcs.in-berlin.de/schrank21_fscd
COMMENT=	FreeBSD service check daemon to monitor services
LICENSE=	2-clause-bsd

CPPFLAGS+=	-DSYSCONFDIR=\"${PKG_SYSCONFDIR}/\"
# Only for platforms with kqueue.
ONLY_FOR_PLATFORM=	NetBSD-[2-9].*-* FreeBSD-[4-9].*-* OpenBSD-*-* DragonFly-*-* Darwin-*-*

RCD_SCRIPTS=	fscd
INSTALLATION_DIRS=	bin sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fscadm/fscadm ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/fscadm/fscadm.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_PROGRAM} ${WRKSRC}/fscd/fscd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/fscd/fscd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/fscd/fscd.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_SCRIPT} ${WRKSRC}/service/service ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/service/service.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
