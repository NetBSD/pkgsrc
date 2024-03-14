# $NetBSD: Makefile,v 1.1 2024/03/14 19:15:29 markd Exp $

DISTNAME=	libunibreak-6.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=adah1972/}
GITHUB_RELEASE=	${DISTNAME:S/-/_/:S/./_/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/adah1972/libunibreak/
COMMENT=	Implementation of line breaking algorithm described in Unicode 5.2.0 SA 14
LICENSE=	zlib

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libunibreak.pc.in

.include "../../mk/bsd.pkg.mk"
