# $NetBSD: Makefile,v 1.1 2004/02/02 15:49:17 soren Exp $
#

DISTNAME=	tpb-0.6.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://savannah.nongnu.org/download/tpb/

MAINTAINER=	soren@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/tpb/
COMMENT=	Utility to enable the IBM ThinkPad(tm) special keys

ONLY_FOR_PLATFORM= *-*-i386

USE_X11=	YES
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tpb
.for f in callback_example.sh nvram.txt tpbrc
	${INSTALL_DATA}	${WRKSRC}/doc/${f}	${PREFIX}/share/doc/tpb
.endfor

.include "../../x11/xosd/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
