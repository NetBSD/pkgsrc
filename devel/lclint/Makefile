# $NetBSD: Makefile,v 1.3 2001/02/16 14:38:33 wiz Exp $
#

VERSION=	2.5q
DISTNAME=	lclint-${VERSION}.src
CATEGORIES=	devel
MASTER_SITES=	http://lclint.cs.virginia.edu/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://lclint.cs.virginia.edu/
COMMENT=	Statically check C programs

WRKSRC=		${WRKDIR}/lclint-${VERSION}/

USE_GMAKE=	YES
GNU_CONFIGURE=  YES
PLIST_SUBST+=	VERSION=${VERSION}

do-build:
	cd ${WRKSRC}; unset CFLAGS; ${GMAKE}

.include "../../mk/bsd.pkg.mk"
