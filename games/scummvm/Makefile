# $NetBSD: Makefile,v 1.5 2003/05/02 11:55:05 wiz Exp $

DISTNAME=	scummvm_0.3.0b-src
PKGREVISION=	1
PKGNAME=	scummvm-0.3.0
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scummvm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://scummvm.sourceforge.net/
COMMENT=	LucasArts Script Creation Utility for Maniac Mansion

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_X11=	yes
HAS_CONFIGURE=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scummvm
	${INSTALL_PROGRAM} ${WRKSRC}/scummvm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scummvm.6 ${PREFIX}/man/man6
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/scummvm

.include "../../devel/SDL/buildlink2.mk"
.include "../../audio/mad/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
