# $NetBSD: Makefile,v 1.7 2003/03/29 12:41:10 jmmv Exp $

DISTNAME=		xevil1.5.1e
PKGNAME=		xevil-1.5.1e
WRKSRC=			${WRKDIR}
CATEGORIES=		games x11
MASTER_SITES=		ftp://ftp.xevil.com/xevil1.5.1e/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.xevil.com/
COMMENT=		violent game of killing, contains profanity

MAKE_ENV=		HOSTTYPE="netbsd" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			INSTALL_MAN="${INSTALL_MAN}"

USE_X11BASE=		yes

.include "../../mk/bsd.pkg.mk"
