# $NetBSD: Makefile,v 1.5 2001/12/30 13:38:06 wiz Exp $
#

VERSION=	2.5q
DISTNAME=	lclint-${VERSION}.src
PKGNAME=	lclint-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://lclint.cs.virginia.edu/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://lclint.cs.virginia.edu/
COMMENT=	Statically check C programs

WRKSRC=		${WRKDIR}/lclint-${VERSION}/

USE_GMAKE=	YES
GNU_CONFIGURE=  YES
PLIST_SUBST+=	VERSION=${VERSION}

.include "../../mk/bsd.pkg.mk"
