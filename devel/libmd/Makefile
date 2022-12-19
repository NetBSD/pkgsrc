# $NetBSD: Makefile,v 1.1 2022/12/19 15:08:04 vins Exp $

DISTNAME=	libmd-1.0.4
CATEGORIES=	devel
MASTER_SITES=	https://archive.hadrons.org/software/libmd/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://www.hadrons.org/software/libmd/
COMMENT=	Message Digest functions from BSD systems
LICENSE=	modified-bsd AND 2-clause-bsd AND isc AND beer-ware

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	src/libmd.pc.in

.include "../../mk/bsd.pkg.mk"
