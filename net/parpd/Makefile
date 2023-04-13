# $NetBSD: Makefile,v 1.16 2023/04/13 17:57:19 roy Exp $

DISTNAME=		parpd-2.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=NetworkConfiguration/}
GITHUB_PROJECT=		parpd
GITHUB_TAG=		${DISTNAME}

MAINTAINER=		roy@NetBSD.org
HOMEPAGE=		https://roy.marples.name/projects/parpd/
COMMENT=		RFC1027 compliant Proxy ARP Daemon
LICENSE=		modified-bsd

USE_LANGUAGES=		c99
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}

RCD_SCRIPTS+=		parpd

.include "../../mk/bsd.pkg.mk"
