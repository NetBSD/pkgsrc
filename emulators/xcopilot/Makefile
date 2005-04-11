# $NetBSD: Makefile,v 1.11 2005/04/11 21:45:46 tv Exp $
#

DISTNAME=		xcopilot-0.6.6
CATEGORIES=		emulators
MASTER_SITES=		http://xcopilot.cuspy.com/build/

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://xcopilot.cuspy.com/
COMMENT=		PalmPilot emulator for X

NOT_FOR_PLATFORM=	*-*-alpha	# suspected LP64 bugs

GNU_CONFIGURE=		YES
USE_X11=		YES

post-extract:
	${RM} -f ${WRKSRC}/mc68k/custom.c

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
