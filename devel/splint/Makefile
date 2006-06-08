# $NetBSD: Makefile,v 1.11 2006/06/08 15:56:43 minskim Exp $
#

VERSION=	3.1.1
DISTNAME=	splint-${VERSION}.src
PKGNAME=	splint-${VERSION}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.splint.org/downloads/
EXTRACT_SUFX= .tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lclint.cs.virginia.edu/
COMMENT=	Statically check C programs

WRKSRC=		${WRKDIR}/splint-${VERSION}
USE_TOOLS+=	gmake lex
GNU_CONFIGURE=  YES

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/splint.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
