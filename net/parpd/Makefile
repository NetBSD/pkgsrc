# $NetBSD: Makefile,v 1.18 2024/08/02 11:33:19 roy Exp $

DISTNAME=		parpd-2.3.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=NetworkConfiguration/}
GITHUB_PROJECT=		parpd
GITHUB_RELEASE=		v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		https://roy.marples.name/projects/parpd/
COMMENT=		RFC1027 compliant Proxy ARP Daemon
LICENSE=		modified-bsd

USE_LANGUAGES=		c11
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

RCD_SCRIPTS+=		parpd

.include "../../mk/bsd.pkg.mk"
