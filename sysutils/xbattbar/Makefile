# $NetBSD: Makefile,v 1.23 2004/04/20 10:31:13 lukem Exp $

DISTNAME=	xbattbar_1.4.2
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	5
CATEGORIES=	sysutils x11
MASTER_SITES=	http://iplab.aist-nara.ac.jp/member/suguru/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://iplab.aist-nara.ac.jp/member/suguru/xbattbar.html
COMMENT=	X11 battery graph for laptops

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_BUILDLINK3=	yes

USE_IMAKE=	# defined

.if !exists(/usr/include/machine/apmvar.h)
PKG_SKIP_REASON=	"APM is not available for ${MACHINE_PLATFORM}"
.endif

.include "../../mk/bsd.pkg.mk"
