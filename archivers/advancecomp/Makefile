# $NetBSD: Makefile,v 1.1.1.1 2004/05/16 01:32:10 xtraeme Exp $
#

DISTNAME=	advancecomp-1.10
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=advancemame/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://advancemame.sourceforge.net/
COMMENT=	Recompression utilities for .zip, .png, .mng and .gz files

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
