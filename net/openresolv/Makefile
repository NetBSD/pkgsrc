# $NetBSD: Makefile,v 1.12 2009/05/19 08:59:27 wiz Exp $
#

DISTNAME=		openresolv-3.3.1
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/openresolv/
MASTER_SITES+=		http://roy.aydogan.net/openresolv/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		http://roy.marples.name/projects/openresolv/
COMMENT=		Framework for managing /etc/resolv.conf
LICENSE=		modified-bsd

USE_LANGUAGES=		# none

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=			${PREFIX}/share/examples/resolvconf
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR} \
			SYSCONFDIR=${PKG_SYSCONFDIR}
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}

CONF_FILES=		${EGDIR}/resolvconf.conf \
			${PKG_SYSCONFDIR}/resolvconf.conf

.include "../../mk/bsd.pkg.mk"
