# $NetBSD: Makefile,v 1.9 2020/01/18 23:33:12 rillig Exp $

DISTNAME=	vblade-14
PKGNAME=	aoe-vblade-14
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aoetools/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://aoetools.sourceforge.net/
COMMENT=	ATA over Ethernet (AoE) server - thin, LAN-based storage protocol

BROKEN_EXCEPT_ON_PLATFORM+=	NetBSD-*-* FreeBSD-*-* Linux-*-* DragonFly-*-*

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

.include "../../mk/bsd.prefs.mk"

do-build:
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
	cd ${WRKSRC} && ${CP} freebsd.c bsd.c && ${MAKE} PLATFORM=bsd
.elif ${OPSYS} == "Linux"
	cd ${WRKSRC} && ${MAKE} PLATFORM=linux
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vblade ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/vbladed ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/vblade.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/

.include "../../mk/bsd.pkg.mk"
