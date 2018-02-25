# $NetBSD: Makefile,v 1.2 2018/02/25 16:09:19 wiz Exp $

DISTNAME=		libdmtx-0.7.4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libdmtx/}

MAINTAINER=		pkgsrc-users@NetBSD.ork
HOMEPAGE=		https://github.com/dmtx/libdmtx
COMMENT=		Software for reading and writing Data Matrix 2D barcodes
LICENSE=		2-clause-bsd

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE+=	libdmtx.pc.in

.include "../../mk/bsd.pkg.mk"
