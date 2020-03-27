# $NetBSD: Makefile,v 1.22 2020/03/27 15:12:27 ryoon Exp $
#

DISTNAME=		xcopilot-0.6.6
PKGREVISION=		1
CATEGORIES=		emulators
#MASTER_SITES=		http://xcopilot.cuspy.com/build/

MAINTAINER=		nathanw@NetBSD.org
#HOMEPAGE=		http://xcopilot.cuspy.com/
COMMENT=		PalmPilot emulator for X
LICENSE=		gnu-gpl-v2

MAKE_JOBS_SAFE=		no

BROKEN_ON_PLATFORM=	${LP64PLATFORMS}	# suspected LP64 bugs

GNU_CONFIGURE=		YES

post-extract:
	${RM} -f ${WRKSRC}/mc68k/custom.c

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
