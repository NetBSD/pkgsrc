# $NetBSD: Makefile,v 1.16 2003/06/02 01:16:51 jschauma Exp $

DISTNAME=	xbattbar_1.4.2
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
CATEGORIES=	sysutils x11
MASTER_SITES=	http://infonet.aist-nara.ac.jp/member/suguru/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://infonet.aist-nara.ac.jp/member/suguru/xbattbar.html
COMMENT=	X11 battery graph for laptops

USE_BUILDLINK2=	# defined

USE_X11BASE=	# defined
USE_IMAKE=	# defined

.if !exists(/usr/include/machine/apmvar.h)
PKG_SKIP_REASON=	"APM is not available for ${MACHINE_PLATFORM}"
.endif

.include "../../mk/bsd.pkg.mk"
