# $NetBSD: Makefile,v 1.27 2013/12/23 11:57:03 wiz Exp $

DISTNAME=	plib-1.8.5
PKGREVISION=	3
CATEGORIES=	games x11
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://plib.sourceforge.net/
COMMENT=	Libraries for writing portable games/realtime interactive apps

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
CPPFLAGS+=	-Dunix=1

.if ${MACHINE_ARCH} == "x86_64"
CXXFLAGS+=	-fPIC
.endif

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
