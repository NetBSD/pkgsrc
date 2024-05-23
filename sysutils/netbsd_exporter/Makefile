# $NetBSD: Makefile,v 1.2 2024/05/23 06:55:00 wiz Exp $

DISTNAME=	netbsd_exporter-0.9.4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=MatthiasPetermann/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.petermann-it.de/en/blog/netbsd_exporter/
COMMENT=	Prometheus exporter for NetBSD
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}

ONLY_FOR_PLATFORM=	NetBSD-*

INSTALL_MAKE_FLAGS+=	MANDIR=${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
