# $NetBSD: Makefile,v 1.6 2001/10/25 21:04:32 agc Exp $
#

DISTNAME=		xcopilot-0.6.6
CATEGORIES=		emulators
MASTER_SITES=		http://xcopilot.cuspy.com/build/

MAINTAINER=		nathanw@netbsd.org
HOMEPAGE=		http://xcopilot.cuspy.com/
COMMENT=		PalmPilot emulator for X

NOT_FOR_PLATFORM=	*-*-alpha	# suspected LP64 bugs

GNU_CONFIGURE=		YES
USE_X11=		YES
USE_XPM=		YES

post-extract:
	${RM} -f ${WRKSRC}/mc68k/custom.c

.include "../../mk/bsd.pkg.mk"
