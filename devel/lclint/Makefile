# $NetBSD: Makefile,v 1.1.1.1 2001/02/09 15:24:23 mjl Exp $
#

VERSION=	2.5q
DISTNAME=	lclint-${VERSION}.src
CATEGORIES=	devel
MASTER_SITES=	http://lclint.cs.virginia.edu/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://lclint.cs.virginia.edu/

WRKSRC=		${WRKDIR}/lclint-${VERSION}/

USE_GMAKE=	YES
GNU_CONFIGURE=  YES

do-build:
	cd ${WRKSRC}; unset CFLAGS; ${GMAKE}

.include "../../mk/bsd.pkg.mk"
