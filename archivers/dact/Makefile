# $NetBSD: Makefile,v 1.2 2002/08/25 21:49:02 jlam Exp $
#

DISTNAME=	dact-0.8.3
CATEGORIES=	archivers
MASTER_SITES=	http://www.rkeene.org/devel/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.rkeene.org/devel/dact/
COMMENT=	dynamic adaptive compression tool

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
