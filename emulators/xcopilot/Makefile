# $NetBSD: Makefile,v 1.17 2009/06/30 00:07:15 joerg Exp $
#

DISTNAME=		xcopilot-0.6.6
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://xcopilot.cuspy.com/build/

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://xcopilot.cuspy.com/
COMMENT=		PalmPilot emulator for X

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

NOT_FOR_PLATFORM=	*-*-alpha	# suspected LP64 bugs

GNU_CONFIGURE=		YES

post-extract:
	${RM} -f ${WRKSRC}/mc68k/custom.c

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
