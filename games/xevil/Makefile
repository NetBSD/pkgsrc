# $NetBSD: Makefile,v 1.9 2004/01/20 12:15:41 agc Exp $

DISTNAME=		xevil1.5.1e
PKGNAME=		xevil-1.5.1e
CATEGORIES=		games x11
MASTER_SITES=		ftp://ftp.xevil.com/xevil1.5.1e/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.xevil.com/
COMMENT=		Violent game of killing, contains profanity

MAKE_ENV=		HOSTTYPE="netbsd" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			INSTALL_MAN="${INSTALL_MAN}"

WRKSRC=			${WRKDIR}
USE_X11BASE=		yes

.include "../../mk/bsd.pkg.mk"
