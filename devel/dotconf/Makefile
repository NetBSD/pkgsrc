# $NetBSD: Makefile,v 1.5 2026/06/09 17:17:25 wiz Exp $

DISTNAME=	dotconf-1.4.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=williamh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/williamh/dotconf
COMMENT=	Simple-to-use and powerful configuration-file parser library
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf

PKGCONFIG_OVERRIDE+=	dotconf.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
