# $NetBSD: Makefile,v 1.3 2002/12/10 12:48:46 wiz Exp $

DISTNAME=	scummvm_0.3.0b-src
PKGNAME=	scummvm-0.3.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scummvm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://scummvm.sourceforge.net/
COMMENT=	LucasArts Script Creation Utility for Maniac Mansion

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_X11=	yes
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
HAS_CONFIGURE=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scummvm
	${INSTALL_PROGRAM} ${WRKSRC}/scummvm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scummvm.6 ${PREFIX}/man/man6
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/scummvm

.include "../../devel/SDL/buildlink2.mk"
.include "../../audio/mad/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
