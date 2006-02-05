# $NetBSD: Makefile,v 1.6 2006/02/05 23:09:00 joerg Exp $
#

DISTNAME=		ckmame-0.7
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://www.nih.at/ckmame/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.nih.at/ckmame/
COMMENT=		Check ROM sets for MAME

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
TEST_TARGET=		check

.include "../../archivers/libzip/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/db1.builtin.mk"

.include "../../mk/bsd.pkg.mk"
