# $NetBSD: Makefile,v 1.17 2003/06/18 22:41:38 seb Exp $

DISTNAME=	xbattbar_1.4.2
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
CATEGORIES=	sysutils x11
MASTER_SITES=	http://iplab.aist-nara.ac.jp/member/suguru/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://iplab.aist-nara.ac.jp/member/suguru/xbattbar.html
COMMENT=	X11 battery graph for laptops

USE_BUILDLINK2=	# defined

USE_X11BASE=	# defined
USE_IMAKE=	# defined

.if !exists(/usr/include/machine/apmvar.h)
PKG_SKIP_REASON=	"APM is not available for ${MACHINE_PLATFORM}"
.endif

.include "../../mk/bsd.pkg.mk"
