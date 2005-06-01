# $NetBSD: Makefile,v 1.12 2005/06/01 18:02:48 jlam Exp $
#

DISTNAME=		xcopilot-0.6.6
CATEGORIES=		emulators
MASTER_SITES=		http://xcopilot.cuspy.com/build/

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://xcopilot.cuspy.com/
COMMENT=		PalmPilot emulator for X

NOT_FOR_PLATFORM=	*-*-alpha	# suspected LP64 bugs

GNU_CONFIGURE=		YES

post-extract:
	${RM} -f ${WRKSRC}/mc68k/custom.c

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
