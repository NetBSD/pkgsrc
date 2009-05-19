# $NetBSD: Makefile,v 1.7 2009/05/19 08:59:27 wiz Exp $
#

DISTNAME=		parpd-1.4
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/parpd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		http://roy.marples.name/projects/parpd/
COMMENT=		RFC1027 compliant Proxy ARP Daemon
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c99

EGDIR=			${PREFIX}/share/examples
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}/man
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}

RCD_SCRIPTS+=		parpd

.include "../../mk/bsd.pkg.mk"
