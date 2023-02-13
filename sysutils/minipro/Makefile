# $NetBSD: Makefile,v 1.4 2023/02/13 23:38:48 thorpej Exp $

MINIPRO_VERS=	0.6

DISTNAME=	minipro-${MINIPRO_VERS}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITLAB:=DavidGriffith/}
GITLAB_PROJECT=	minipro
GITLAB_RELEASE=	${MINIPRO_VERS}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://gitlab.com/DavidGriffith/minipro/
COMMENT=	Control the MiniPRO TL866xx series of chip programmers
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
