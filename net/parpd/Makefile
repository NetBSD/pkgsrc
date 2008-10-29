# $NetBSD: Makefile,v 1.3 2008/10/29 13:25:01 obache Exp $
#

DISTNAME=		parpd-1.2
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/parpd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@marples.name
HOMEPAGE=		http://roy.marples.name/projects/parpd/
COMMENT=		RFC1027 compliant Proxy ARP Daemon

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c99

EGDIR=			${PREFIX}/share/examples
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}/man
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}

RCD_SCRIPTS+=		parpd

.include "../../mk/bsd.pkg.mk"
