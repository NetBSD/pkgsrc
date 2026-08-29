# $NetBSD: Makefile,v 1.4 2026/08/29 20:03:06 wiz Exp $

DISTNAME=	netbsd_exporter-0.9.4
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=MatthiasPetermann/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MatthiasPetermann/netbsd_exporter
COMMENT=	Prometheus exporter for NetBSD
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/${DISTNAME}

ONLY_FOR_PLATFORM=	NetBSD-*

INSTALL_MAKE_FLAGS+=	MANDIR=${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
