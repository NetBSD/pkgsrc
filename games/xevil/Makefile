# $NetBSD: Makefile,v 1.10 2004/05/23 20:58:42 danw Exp $

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
USE_BUILDLINK3=		yes

.include "../../mk/bsd.pkg.mk"
