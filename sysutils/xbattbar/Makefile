# $NetBSD: Makefile,v 1.27 2006/02/05 23:10:57 joerg Exp $

DISTNAME=	xbattbar_1.4.2
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	6
CATEGORIES=	sysutils x11
MASTER_SITES=	http://iplab.aist-nara.ac.jp/member/suguru/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://iplab.aist-nara.ac.jp/member/suguru/xbattbar.html
COMMENT=	X11 battery graph for laptops

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

USE_IMAKE=	yes

.if !exists(/usr/include/machine/apmvar.h)
PKG_SKIP_REASON+=	"APM is not available for ${MACHINE_PLATFORM}"
.endif

.include "../../mk/bsd.pkg.mk"
