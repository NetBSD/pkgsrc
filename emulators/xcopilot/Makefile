# $NetBSD: Makefile,v 1.14 2006/12/15 20:32:55 joerg Exp $
#

DISTNAME=		xcopilot-0.6.6
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://xcopilot.cuspy.com/build/

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://xcopilot.cuspy.com/
COMMENT=		PalmPilot emulator for X

NOT_FOR_PLATFORM=	*-*-alpha	# suspected LP64 bugs

GNU_CONFIGURE=		YES

post-extract:
	${RM} -f ${WRKSRC}/mc68k/custom.c

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
