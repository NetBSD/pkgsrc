# $NetBSD: Makefile,v 1.3 2023/06/06 12:41:59 riastradh Exp $

DISTNAME=	dvd-vr-0.9.7
CATEGORIES=	multimedia
MASTER_SITES=	http://www.pixelbeat.org/programs/dvd-vr/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.pixelbeat.org/programs/dvd-vr/
COMMENT=	Utility to identify and optionally copy recordings from DVD-VR
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}

USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
