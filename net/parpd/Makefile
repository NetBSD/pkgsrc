# $NetBSD: Makefile,v 1.9 2010/04/21 19:22:10 roy Exp $
#

DISTNAME=		parpd-1.5
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/parpd/ \
					http://roy.aydogan.net/parpd/
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
