# $NetBSD: Makefile,v 1.8 2003/07/21 16:50:02 martti Exp $

DISTNAME=		xevil1.5.1e
PKGNAME=		xevil-1.5.1e
WRKSRC=			${WRKDIR}
CATEGORIES=		games x11
MASTER_SITES=		ftp://ftp.xevil.com/xevil1.5.1e/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.xevil.com/
COMMENT=		Violent game of killing, contains profanity

MAKE_ENV=		HOSTTYPE="netbsd" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			INSTALL_MAN="${INSTALL_MAN}"

USE_X11BASE=		yes

.include "../../mk/bsd.pkg.mk"
