# $NetBSD: Makefile,v 1.1.1.1.2.1 2002/05/11 02:08:48 jlam Exp $
#

DISTNAME=	dact-0.8.3
CATEGORIES=	archivers
MASTER_SITES=	http://www.rkeene.org/devel/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.rkeene.org/devel/dact/
COMMENT=	dynamic adaptive compression tool

USE_BUILDLINK2_ONLY=	YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
