# $NetBSD: Makefile,v 1.2 2004/07/28 02:45:06 minskim Exp $
#

DISTNAME=	advancecomp-1.10
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=advancemame/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://advancemame.sourceforge.net/
COMMENT=	Recompression utilities for .zip, .png, .mng and .gz files

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
