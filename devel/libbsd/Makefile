# $NetBSD: Makefile,v 1.2 2022/08/15 22:56:37 tnn Exp $

DISTNAME=	libbsd-0.10.0
CATEGORIES=	devel
MASTER_SITES=	http://libbsd.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	matthias@rampke.de
HOMEPAGE=	https://libbsd.freedesktop.org/
COMMENT=	Compatibility library for BSD functions under other systems
LICENSE=	original-bsd

NOT_FOR_PLATFORM=	NetBSD-*-* FreeBSD-*-* OpenBSD-*-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
