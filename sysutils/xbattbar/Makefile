# $NetBSD: Makefile,v 1.30 2007/07/25 15:09:32 xtraeme Exp $

DISTNAME=	xbattbar_1.4.2
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	7
CATEGORIES=	sysutils x11
MASTER_SITES=	http://iplab.aist-nara.ac.jp/member/suguru/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://iplab.aist-nara.ac.jp/member/suguru/xbattbar.html
COMMENT=	X11 battery graph for laptops

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

USE_IMAKE=	yes

.if !exists(/usr/include/machine/apmvar.h)
PKG_SKIP_REASON+=	"APM is not available for ${MACHINE_PLATFORM}"
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
