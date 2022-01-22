# $NetBSD: Makefile,v 1.1 2022/01/22 17:52:53 thorpej Exp $

MINIPRO_VERS=	0.5

DISTNAME=	minipro-${MINIPRO_VERS}
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.com/DavidGriffith/minipro/-/archive/${MINIPRO_VERS}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://gitlab.com/DavidGriffith/minipro/
COMMENT=	Control the MiniPRO TL866xx series of chip programmers
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
