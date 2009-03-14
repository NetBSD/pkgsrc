# $NetBSD: Makefile,v 1.3 2009/03/14 22:33:20 roy Exp $
#

DISTNAME=		openresolv-2.1
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/openresolv/
MASTER_SITES+=		http://roy.aydogan.net/openresolv/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@marples.name
HOMEPAGE=		http://roy.marples.name/projects/openresolv/
COMMENT=		Framework for managing /etc/resolv.conf

USE_LANGUAGES=		# none

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_SYSCONFSUBDIR=	resolvconf
EGDIR=			${PREFIX}/share/examples/resolvconf

MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR} \
			SYSCONFDIR=${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}

OWN_DIRS=		${PKG_SYSCONFDIR}/update.d
CONF_FILES=		${EGDIR}/resolv.conf.head \
			${PKG_SYSCONFDIR}/resolv.conf.head

.include "../../mk/bsd.pkg.mk"