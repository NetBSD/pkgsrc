# $NetBSD: Makefile,v 1.7 2001/11/01 12:21:38 tron Exp $
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

EVAL_PREFIX+=		XPMDIR=xpm

CFLAGS+=		-I${XPMDIR}/include
LDFLAGS+=		-L${XPMDIR}/lib -Wl,-R${XPMDIR}/lib

post-extract:
	${RM} -f ${WRKSRC}/mc68k/custom.c

.include "../../mk/bsd.pkg.mk"
