# $NetBSD: Makefile,v 1.9 2003/07/17 21:36:29 grant Exp $
#

DISTNAME=		xcopilot-0.6.6
CATEGORIES=		emulators
MASTER_SITES=		http://xcopilot.cuspy.com/build/

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://xcopilot.cuspy.com/
COMMENT=		PalmPilot emulator for X

NOT_FOR_PLATFORM=	*-*-alpha	# suspected LP64 bugs

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_X11=		YES

post-extract:
	${RM} -f ${WRKSRC}/mc68k/custom.c

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
