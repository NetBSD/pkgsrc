# $NetBSD: Makefile,v 1.1.1.1 2008/10/09 00:24:28 joerg Exp $
#

DISTNAME=		parpd-1.0
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

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	parpd.c parpd.8
SUBST_SED.paths=	-e 's,/etc,${PKG_SYSCONFDIR},'
SUBST_STAGE.paths=	pre-configure

RCD_SCRIPTS+=		parpd

.include "../../mk/bsd.pkg.mk"
