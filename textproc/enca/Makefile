# $NetBSD: Makefile,v 1.11 2026/06/23 10:05:27 wiz Exp $

DISTNAME=		enca-1.22
CATEGORIES=		textproc converters
MASTER_SITES=		${MASTER_SITE_GITHUB:=Project-OSS-Revival/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/Project-OSS-Revival/enca
COMMENT=		Extremely Naive Charset Analyser
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE+=	enca.pc.in

.include "../../mk/bsd.pkg.mk"
