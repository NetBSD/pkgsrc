# $NetBSD: Makefile,v 1.2 2005/06/30 19:47:21 minskim Exp $
#

DISTNAME=		ckmame-0.6
CATEGORIES=		emulators
MASTER_SITES=		http://www.nih.at/ckmame/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dillo@NetBSD.org
HOMEPAGE=		http://www.nih.at/ckmame/
COMMENT=		Check ROM sets for MAME

GNU_CONFIGURE=		yes
TEST_TARGET=		check

.include "../../archivers/libzip/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/db1.builtin.mk"

.include "../../mk/bsd.pkg.mk"
