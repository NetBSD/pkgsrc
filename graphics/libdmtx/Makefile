# $NetBSD: Makefile,v 1.1 2018/02/01 18:38:11 markd Exp $
#

DISTNAME=		libdmtx-0.7.4
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libdmtx/}

MAINTAINER=		pkgsrc-users@NetBSD.ork
HOMEPAGE=		https://libdmtx.sourceforge.net/
COMMENT=		Software for reading and writing Data Matrix 2D barcodes
LICENSE=		2-clause-bsd

USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

PKGCONFIG_OVERRIDE+=	libdmtx.pc.in

.include "../../mk/bsd.pkg.mk"
