# $NetBSD: Makefile,v 1.10 2004/04/11 08:36:43 snj Exp $
#

DISTNAME=		xcopilot-0.6.6
CATEGORIES=		emulators
MASTER_SITES=		http://xcopilot.cuspy.com/build/

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://xcopilot.cuspy.com/
COMMENT=		PalmPilot emulator for X

NOT_FOR_PLATFORM=	*-*-alpha	# suspected LP64 bugs

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_X11=		YES

post-extract:
	${RM} -f ${WRKSRC}/mc68k/custom.c

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
