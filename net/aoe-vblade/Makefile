# $NetBSD: Makefile,v 1.1.1.1 2007/01/10 20:39:35 agc Exp $

DISTNAME=	vblade-14
PKGNAME=	aoe-vblade-14
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aoetools/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aoetools.sourceforge.net/
COMMENT=	ATA over Ethernet (AoE) server - thin, LAN-based storage protocol

do-build:
	cd ${WRKSRC} && ${CP} freebsd.c bsd.c && ${MAKE} PLATFORM=bsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vblade ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/vbladed ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/vblade.8 ${PREFIX}/${PKGMANDIR}/man8/

.include "../../mk/bsd.pkg.mk"
