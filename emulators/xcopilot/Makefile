# $NetBSD: Makefile,v 1.16 2008/06/20 01:09:19 joerg Exp $
#

DISTNAME=		xcopilot-0.6.6
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://xcopilot.cuspy.com/build/

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://xcopilot.cuspy.com/
COMMENT=		PalmPilot emulator for X

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	*-*-alpha	# suspected LP64 bugs

GNU_CONFIGURE=		YES

post-extract:
	${RM} -f ${WRKSRC}/mc68k/custom.c

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
