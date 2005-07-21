# $NetBSD: Makefile,v 1.3 2005/07/21 16:29:49 wiz Exp $
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
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/db1.builtin.mk"

.include "../../mk/bsd.pkg.mk"
