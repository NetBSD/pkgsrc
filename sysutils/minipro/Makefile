# $NetBSD: Makefile,v 1.5 2024/04/21 20:37:52 thorpej Exp $

MINIPRO_VERS=	0.7

DISTNAME=	minipro-${MINIPRO_VERS}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITLAB:=DavidGriffith/}
GITLAB_PROJECT=	minipro
GITLAB_RELEASE=	${MINIPRO_VERS}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	thorpej@NetBSD.org
HOMEPAGE=	https://gitlab.com/DavidGriffith/minipro/
COMMENT=	Control the MiniPRO TL866xx / Xgecu family of chip programmers
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
