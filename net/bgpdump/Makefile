# $NetBSD: Makefile,v 1.1 2026/09/25 13:30:30 drixter Exp $

DISTNAME=	libbgpdump-1.6.2
PKGNAME=	${DISTNAME:S/libbgpdump/bgpdump/}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=RIPE-NCC/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/RIPE-NCC/bgpdump
COMMENT=	BGP dump utility and library
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	automake autoconf autoreconf
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
