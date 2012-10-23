# $NetBSD: Makefile,v 1.34 2012/10/23 19:51:35 asau Exp $

DISTNAME=	xbattbar_1.4.2
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	9
CATEGORIES=	sysutils x11
MASTER_SITES=	http://iplab.aist-nara.ac.jp/member/suguru/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://iplab.aist-nara.ac.jp/member/suguru/xbattbar.html
COMMENT=	X11 battery graph for laptops

NOT_FOR_PLATFORM=     Darwin-*-*

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

USE_IMAKE=	yes

.if !exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=	-D_NO_APM
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
