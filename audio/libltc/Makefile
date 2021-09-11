# $NetBSD: Makefile,v 1.1 2021/09/11 10:29:15 nia Exp $

DISTNAME=	libltc-1.3.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=x42/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://x42.github.io/libltc/
COMMENT=	Linear/Logitudinal Time Code (LTC) Library
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	ltc.pc.in

.include "../../mk/bsd.pkg.mk"
