# $NetBSD: Makefile,v 1.9 2005/05/24 13:54:50 rillig Exp $
#

DISTNAME=	mp3_check-1.98
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3check/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mp3check.sourceforge.net/
COMMENT=	mp3 file checker

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3_check ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
