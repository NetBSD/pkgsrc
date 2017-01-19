# $NetBSD: Makefile,v 1.11 2017/01/19 18:52:20 agc Exp $
#

DISTNAME=		parpd-1.5
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/parpd/
MASTER_SITES+=		http://roy.aydogan.net/parpd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		http://roy.marples.name/projects/parpd/
COMMENT=		RFC1027 compliant Proxy ARP Daemon
LICENSE=		modified-bsd

USE_LANGUAGES=		c99

EGDIR=			${PREFIX}/share/examples
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}/man
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}

RCD_SCRIPTS+=		parpd

.include "../../mk/bsd.pkg.mk"
