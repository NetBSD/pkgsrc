# $NetBSD: Makefile,v 1.4 2022/07/25 11:12:20 wiz Exp $

DISTNAME=	shine-3.1.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=savonet/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/savonet/shine
COMMENT=	Fast fixed-point mp3 encoding
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	shine.pc.in

.include "../../mk/bsd.pkg.mk"
