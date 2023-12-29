# $NetBSD: Makefile,v 1.1 2023/12/29 20:55:02 wiz Exp $

DISTNAME=	0.9.3
PKGNAME=	netbsd_exporter-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	https://forge.petermann-it.de/mpeterma/netbsd_exporter/archive/
DIST_SUBDIR=	netbsd_exporter

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.petermann-it.de/en/blog/netbsd_exporter/
COMMENT=	Prometheus exporter for NetBSD
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/netbsd_exporter

ONLY_FOR_PLATFORM=	NetBSD-*

INSTALL_MAKE_FLAGS+=	MANDIR=${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
