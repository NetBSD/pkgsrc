# $NetBSD: Makefile,v 1.10 2003/06/02 01:19:35 jschauma Exp $

DISTNAME=	scummvm-0.4.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scummvm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@netbsd.org
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
