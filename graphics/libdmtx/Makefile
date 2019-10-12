# $NetBSD: Makefile,v 1.3 2019/10/12 09:13:15 bsiegert Exp $

DISTNAME=		libdmtx-0.7.4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libdmtx/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/dmtx/libdmtx
COMMENT=		Software for reading and writing Data Matrix 2D barcodes
LICENSE=		2-clause-bsd

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE+=	libdmtx.pc.in

.include "../../mk/bsd.pkg.mk"
