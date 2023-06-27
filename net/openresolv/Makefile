# $NetBSD: Makefile,v 1.35 2023/06/27 17:13:29 roy Exp $

DISTNAME=		openresolv-3.13.2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=NetworkConfiguration/}
GITHUB_PROJECT=		openresolv
GITHUB_RELEASE=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		https://roy.marples.name/projects/openresolv/
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
