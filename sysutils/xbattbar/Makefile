# $NetBSD: Makefile,v 1.3 2000/12/29 16:30:05 dmcmahill Exp $

DISTNAME=	xbattbar_1.4
PKGNAME=	xbattbar-1.4
CATEGORIES=	sysutils x11
MASTER_SITES=	http://infonet.aist-nara.ac.jp/member/suguru/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://infonet.aist-nara.ac.jp/member/suguru/xbattbar.html

USE_X11BASE=	YES
USE_IMAKE=	YES
WRKSRC=		${WRKDIR}/xbattbar

.if !exists(/usr/include/machine/apmvar.h)
IGNORE+=	"APM is not available for ${MACHINE_PLATFORM}"
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/xbattbar.man ${PREFIX}/man/man1/xbattbar.1

.include "../../mk/bsd.pkg.mk"
