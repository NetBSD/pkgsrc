# $NetBSD: Makefile,v 1.15 2010/11/05 09:24:58 roy Exp $
#

DISTNAME=		openresolv-3.4.0
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/openresolv/
MASTER_SITES+=		http://roy.aydogan.net/openresolv/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		http://roy.marples.name/projects/openresolv/
COMMENT=		Framework for managing /etc/resolv.conf
LICENSE=		modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# none
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/resolvconf
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}

CONF_FILES=		${EGDIR}/resolvconf.conf \
			${PKG_SYSCONFDIR}/resolvconf.conf

.include "../../mk/bsd.pkg.mk"
