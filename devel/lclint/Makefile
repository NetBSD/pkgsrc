# $NetBSD: Makefile,v 1.4 2001/08/20 02:53:52 hubertf Exp $
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
	cd ${WRKSRC}; unset CFLAGS CPPFLAGS; ${MAKE_PROGRAM}

.include "../../mk/bsd.pkg.mk"
