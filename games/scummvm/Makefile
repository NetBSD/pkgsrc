# $NetBSD: Makefile,v 1.1.1.1 2002/09/12 00:38:30 wiz Exp $

DISTNAME=	scummvm_0.2.0-src
PKGNAME=	scummvm-0.2.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scummvm/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://scummvm.sourceforge.net/
COMMENT=	LucasArts Script Creation Utility for Maniac Mansion

USE_BUILDLINK2=	yes
WRKSRC=		${WRKDIR}/scummvm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scummvm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scummvm.6 ${PREFIX}/man/man6

.include "../../devel/SDL/buildlink2.mk"
#.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
