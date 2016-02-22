# $NetBSD: Makefile,v 1.26 2016/02/22 10:11:22 roy Exp $
#

DISTNAME=		openresolv-3.7.3
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/openresolv/
MASTER_SITES+=		http://roy.aydogan.net/openresolv/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		http://roy.marples.name/projects/openresolv/
COMMENT=		Framework for managing /etc/resolv.conf
LICENSE=		modified-bsd

USE_LANGUAGES=		# none
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--libexecdir=${PREFIX}/libexec/resolvconf
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

MAKE_ENV+=		INSTALL=${TOOLS_PATH.install:Q}

EGDIR=			${PREFIX}/share/examples/resolvconf
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}

CONF_FILES=		${EGDIR}/resolvconf.conf \
			${PKG_SYSCONFDIR}/resolvconf.conf

.include "../../mk/bsd.pkg.mk"
