# $NetBSD: Makefile,v 1.19 2003/10/19 09:25:02 agc Exp $

DISTNAME=	xbattbar_1.4.2
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	3
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
CATEGORIES=	sysutils x11
MASTER_SITES=	http://iplab.aist-nara.ac.jp/member/suguru/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://iplab.aist-nara.ac.jp/member/suguru/xbattbar.html
COMMENT=	X11 battery graph for laptops

USE_BUILDLINK2=	# defined

USE_X11BASE=	# defined
USE_IMAKE=	# defined

.if !exists(/usr/include/machine/apmvar.h)
PKG_SKIP_REASON=	"APM is not available for ${MACHINE_PLATFORM}"
.endif

.include "../../mk/bsd.pkg.mk"
