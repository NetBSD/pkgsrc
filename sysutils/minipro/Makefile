# $NetBSD: Makefile,v 1.7 2025/04/27 17:46:01 thorpej Exp $

MINIPRO_VERS=	0.7.3

DISTNAME=	minipro-${MINIPRO_VERS}
#PKGREVISION=	1
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

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	MAN_INSTDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
