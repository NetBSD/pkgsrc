# $NetBSD: Makefile,v 1.3 2022/05/24 10:22:17 nikita Exp $

MINIPRO_VERS=	0.5

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

USE_TOOLS+=	gmake pkg-config bash:run

# likely could be made portable...
REPLACE_BASH+=	miniprohex

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
