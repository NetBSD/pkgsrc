# $NetBSD: Makefile,v 1.4 2001/01/26 01:28:26 jlam Exp $

DISTNAME=	${PKGNAME:S/-/_/}
PKGNAME=	xbattbar-1.4.1
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	sysutils x11
MASTER_SITES=	http://infonet.aist-nara.ac.jp/member/suguru/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://infonet.aist-nara.ac.jp/member/suguru/xbattbar.html

USE_X11BASE=	# defined
USE_IMAKE=	# defined

.if !exists(/usr/include/machine/apmvar.h)
IGNORE+=	"APM is not available for ${MACHINE_PLATFORM}"
.endif

.include "../../mk/bsd.pkg.mk"
