# $NetBSD: Makefile,v 1.2 2001/02/09 16:17:16 mjl Exp $
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
PLIST_SUBST+=	VERSION=${VERSION}

do-build:
	cd ${WRKSRC}; unset CFLAGS; ${GMAKE}

.include "../../mk/bsd.pkg.mk"
