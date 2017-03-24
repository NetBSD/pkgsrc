# $NetBSD: Makefile,v 1.13 2017/03/24 16:49:10 roy Exp $
#

DISTNAME=		parpd-1.7
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/parpd/
MASTER_SITES+=		http://roy.marples.name/downloads/parpd/
MASTER_SITES+=		http://roy.aydogan.net/parpd/
EXTRACT_SUFX=		.tar.xz

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
