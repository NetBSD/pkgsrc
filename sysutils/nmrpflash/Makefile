# $NetBSD: Makefile,v 1.2 2023/11/18 02:44:58 riastradh Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	nmrpflash-0.9.22
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=jclehner/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jclehner/nmrpflash/
COMMENT=	Netgear unbrick utility
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config

BUILD_TARGET=	nmrpflash

INSTALLATION_DIRS+=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nmrpflash ${DESTDIR}${PREFIX}/sbin

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
