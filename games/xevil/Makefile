# $NetBSD: Makefile,v 1.6 2001/09/09 20:36:29 agc Exp $

DISTNAME=		xevil1.5.1e
PKGNAME=		xevil-1.5.1e
CATEGORIES=		games x11
MASTER_SITES=		ftp://ftp.xevil.com/xevil1.5.1e/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.xevil.com/
COMMENT=		violent game of killing, contains profanity

WRKSRC=			${WRKDIR}
MAKE_ENV=		HOSTTYPE="netbsd" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			INSTALL_MAN="${INSTALL_MAN}"

USE_X11BASE=		yes

.include "../../mk/bsd.pkg.mk"
