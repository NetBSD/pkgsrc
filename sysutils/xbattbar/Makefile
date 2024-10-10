# $NetBSD: Makefile,v 1.38 2024/10/10 17:25:57 nia Exp $

DISTNAME=	xbattbar_1.4.2
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	10
CATEGORIES=	sysutils x11
MASTER_SITES=	http://iplab.aist-nara.ac.jp/member/suguru/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://iplab.aist-nara.ac.jp/member/suguru/xbattbar.html
COMMENT=	X11 battery graph for laptops

ONLY_FOR_PLATFORM=	FreeBSD-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-*
ONLY_FOR_PLATFORM+=	Linux-*-*

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

USE_IMAKE=	yes

.if !exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=	-D_NO_APM
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
