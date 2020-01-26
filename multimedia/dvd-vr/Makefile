# $NetBSD: Makefile,v 1.2 2020/01/26 17:31:45 rillig Exp $

DISTNAME=	dvd-vr-0.9.7
CATEGORIES=	multimedia
MASTER_SITES=	http://www.pixelbeat.org/programs/dvd-vr/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.pixelbeat.org/programs/dvd-vr/
COMMENT=	Utility to identify and optionally copy recordings from DVD-VR
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
